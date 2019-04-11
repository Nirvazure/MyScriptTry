package com.lfr.firstcodetest;

import java.util.List;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;
import org.json.JSONArray;
import org.json.JSONObject;

import com.example.firstcodetest.R;

import android.app.Activity;
import android.content.Context;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.widget.TextView;
import android.widget.Toast;

public class LocationTest extends Activity{
	
	public static final int SHOW_LOCATION=0;
	
	private TextView positionTextView;
	private TextView positionTextView2;
	private LocationManager locationManager;
	private String provider;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO 自动生成的方法存根
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_location);
		positionTextView=(TextView)findViewById(R.id.position_text_view);
		positionTextView2=(TextView)findViewById(R.id.position_text_view2);
		locationManager=(LocationManager)getSystemService(Context.LOCATION_SERVICE);
		
		List<String> providerList=locationManager.getProviders(true);
		if(providerList.contains(LocationManager.GPS_PROVIDER)){
			provider=LocationManager.GPS_PROVIDER;
		}else if (providerList.contains(LocationManager.NETWORK_PROVIDER)) {
			provider=LocationManager.NETWORK_PROVIDER;
		}else {
			Toast.makeText(this, "No Location Provider to use", Toast.LENGTH_SHORT).show();
			return;
		}
		
		Location location=locationManager.getLastKnownLocation(provider);
		if (location!=null) {
			showLocation(location);
		}
		locationManager.requestLocationUpdates(provider, 5000, 1, locationListener);
	}
	
	@Override
	protected void onDestroy() {
		// TODO 自动生成的方法存根
		super.onDestroy();
		if (locationManager!=null) {
			locationManager.removeUpdates(locationListener);
		}
	}
	
	private void showLocation(Location location) {
		// TODO 自动生成的方法存根
		String currentPosition="latitude is"+location.hasAltitude()+"\n"+"longitude is "+location.getLongitude()+"\n time is"+location.getTime();
		positionTextView.setText(currentPosition);
	}
	
	private void showLocation2(final Location location) {
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				// TODO 自动生成的方法存根
				try {
					//组装反向地理编码的接口地址
					StringBuilder uri=new StringBuilder();
					uri.append("http://maps.googleapis.com/maps/api/geocode/json?latlng=");
					uri.append(location.getLatitude()).append(",");
					uri.append(location.getLongitude());
					uri.append("&sensor=false");
					HttpClient httpClient=new DefaultHttpClient();
					HttpGet httpGet=new HttpGet(uri.toString());
					//消息头中指定语言
					httpGet.addHeader("Accept-Language","zh-CN");
					HttpResponse httpResponse=httpClient.execute(httpGet);
					if (httpResponse.getStatusLine().getStatusCode()==200) {
						HttpEntity entity=httpResponse.getEntity();
						String response=EntityUtils.toString(entity,"utf-8");
						JSONObject jsonObject=new JSONObject(response);
						//获取results节点下的位置信息
						JSONArray resultArray=jsonObject.getJSONArray("results");
						if (resultArray.length()>0) {
							JSONObject jsonObject2=resultArray.getJSONObject(0);
							//取出格式化后的位置信息
							String address=jsonObject2.getString("formatted_address");
							Message message=new Message();
							message.what=SHOW_LOCATION;
							message.obj=address;
							handler.sendMessage(message);
						}
					}
				} catch (Exception e) {
					// TODO: handle exception
					e.printStackTrace();
				}
			}
		}).start();
	}
	
	private Handler handler=new Handler(){
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case SHOW_LOCATION:
				String currentPosition=(String)msg.obj;
				positionTextView2.setText(currentPosition);
				break;
			default:
				break;
			}
		}
	};

	LocationListener locationListener=new LocationListener() {
		
		@Override
		public void onStatusChanged(String arg0, int arg1, Bundle arg2) {
			// TODO 自动生成的方法存根
			
		}
		
		@Override
		public void onProviderEnabled(String arg0) {
			// TODO 自动生成的方法存根
			
		}
		
		@Override
		public void onProviderDisabled(String arg0) {
			// TODO 自动生成的方法存根
			
		}
		
		@Override
		public void onLocationChanged(Location location) {
			// 更新设备信息
			showLocation(location);
		}
	};
	
}
