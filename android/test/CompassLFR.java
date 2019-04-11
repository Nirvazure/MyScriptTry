package com.lfr.firstcodetest;

import com.example.firstcodetest.R;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.animation.Animation;
import android.view.animation.RotateAnimation;
import android.widget.ImageView;
import android.widget.Toast;
import android.app.Activity;
import android.content.Context;

public class CompassLFR extends Activity {

	private SensorManager sensorManager;
	private ImageView compassImg;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.compass_lfr);
		compassImg=(ImageView)findViewById(R.id.compass_img);
		sensorManager=(SensorManager)getSystemService(Context.SENSOR_SERVICE);
		Sensor magneticSensor=sensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
		Sensor accelerometerSensor=sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
		sensorManager.registerListener(listener, magneticSensor,sensorManager.SENSOR_DELAY_GAME);
		sensorManager.registerListener(listener, accelerometerSensor,sensorManager.SENSOR_DELAY_GAME);
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

		float[] accelerometerValues=new float[3];
		float[] magneticValues=new float[3];

		private float lastRotateDegree;

		@Override
		public void onSensorChanged(SensorEvent event) {
			// 判断当前是加速度传感器还是地磁传感器
			if (event.sensor.getType()==Sensor.TYPE_ACCELEROMETER) {
				//赋值时用clone方法
				accelerometerValues=event.values.clone();
				float xValue=Math.abs(event.values[0]);
				float yValue=Math.abs(event.values[1]);
				float zValue=Math.abs(event.values[2]);
				if (xValue>15||yValue>15||zValue>15) {
					Toast.makeText(CompassLFR.this, "you chick the phone", Toast.LENGTH_SHORT);
				}
			}else if (event.sensor.getType()==Sensor.TYPE_MAGNETIC_FIELD) {
				magneticValues=event.values.clone();
			}
			float[] R=new float[9];
			float[] values=new float[3];
			SensorManager.getRotationMatrix(R, null, accelerometerValues, magneticValues);
			SensorManager.getOrientation(R, values);
			//将计算的角度取反，用于旋转指南针背景图

			float rotateDegree=-(float)Math.toDegrees(values[0]);
			if (Math.abs(rotateDegree-lastRotateDegree)>1) {
				RotateAnimation animation=new RotateAnimation(lastRotateDegree, rotateDegree,Animation.RELATIVE_TO_SELF,0.5f,Animation.RELATIVE_TO_SELF,0.5f);
				animation.setFillAfter(true);
				compassImg.startAnimation(animation);
				lastRotateDegree=rotateDegree;
			}

			//values[0]表示手机围绕Z轴旋转的弧度，用toDegrees方法转换成角度并打印
			Log.d("MainActivity", "value[0] is "+values[0]);
		}

		@Override
		public void onAccuracyChanged(Sensor arg0, int arg1) {
			// TODO 自动生成的方法存根
		}
	};

}
