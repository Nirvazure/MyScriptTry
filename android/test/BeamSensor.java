package com.lfr.firstcodetest;

import com.example.firstcodetest.R;

import android.app.Activity;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.TextView;

public class BeamSensor extends Activity{

	private SensorManager sensorManager;
	
	private TextView lightLevel;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO 自动生成的方法存根
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_beamsensor);
		lightLevel=(TextView)findViewById(R.id.light_level);
		sensorManager=(SensorManager)getSystemService(Context.SENSOR_SERVICE);
		Sensor sensor=sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
		sensorManager.registerListener(listener, sensor, SensorManager.SENSOR_DELAY_NORMAL);
	}
	
	@Override
	protected void onDestroy() {
		// TODO 自动生成的方法存根
		super.onDestroy();
		if (sensorManager!=null) {
			sensorManager.unregisterListener(listener);
		}
	}
	
	private SensorEventListener listener=new SensorEventListener() {
		
		@Override
		public void onSensorChanged(SensorEvent event) {
			// TODO 自动生成的方法存根
			float value=event.values[0];
			lightLevel.setText("Current light level is"+value+"lx");
		}
		
		@Override
		public void onAccuracyChanged(Sensor sensor, int accuracy) {
			// TODO 自动生成的方法存根
			
		}
	};

}
