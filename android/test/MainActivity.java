package com.lfr.firstcodetest;

import com.example.firstcodetest.R;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity implements android.view.View.OnClickListener{

	private Button beamSensor;
	private Button webViewButton;
	private Button takePhotoButton;
	private Button smsTestButton;
	private Button locationTestButton;
	private Button compassButton;
	private Button rotateAnimeLaucher;
	private Button calculateButton;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		beamSensor=(Button)findViewById(R.id.beam_sensor);
		webViewButton=(Button)findViewById(R.id. webview);
		takePhotoButton=(Button)findViewById(R.id.take_photo);
		smsTestButton=(Button)findViewById(R.id.sms_test);
		locationTestButton=(Button)findViewById(R.id.location_tests);
		compassButton=(Button)findViewById(R.id.compass_button);
		rotateAnimeLaucher=(Button)findViewById(R.id.rotate_button);
		calculateButton=(Button)findViewById(R.id.calculate_button);
		beamSensor.setOnClickListener(this);
		webViewButton.setOnClickListener(this);
		takePhotoButton.setOnClickListener(this);
		smsTestButton.setOnClickListener(this);
		locationTestButton.setOnClickListener(this);
		compassButton.setOnClickListener(this);
		rotateAnimeLaucher.setOnClickListener(this);
		calculateButton.setOnClickListener(this);
	}

	@Override
	public void onClick(View view) {
		Intent intent=null;
		// TODO 自动生成的方法存根
		switch (view.getId()) {
		case R.id.beam_sensor:
			intent=new Intent(MainActivity.this,BeamSensor.class);
			startActivity(intent);
			break;
		case R.id.location_tests:
			intent=new Intent(MainActivity.this,LocationTest.class);
			startActivity(intent);
			break;
		case R.id.webview:
			intent=new Intent(MainActivity.this,WebviewTest.class);
			startActivity(intent);
			break;
		case R.id.sms_test:
			intent=new Intent(MainActivity.this,SmsTest.class);
			startActivity(intent);
			break;
		case R.id.take_photo:
			intent=new Intent(MainActivity.this,TakePhotoActivity.class);
			startActivity(intent);
			break;
		case R.id.compass_button:
			intent=new Intent(MainActivity.this,CompassLFR.class);
			startActivity(intent);
			break;
		case R.id.rotate_button:
			intent=new Intent(MainActivity.this,RotateTest.class);
			startActivity(intent);
			break;
		case R.id.calculate_button:
			intent=new Intent(MainActivity.this,ComplieCalculatorActivity.class);
			startActivity(intent);
			break;
		default:
			break;
		}
	}

}
