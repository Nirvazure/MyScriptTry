package com.lfr.firstcodetest;

import java.util.Random;

import com.example.firstcodetest.R;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.animation.Animation;
import android.view.animation.RotateAnimation;
import android.widget.Button;
import android.widget.ImageView;

public class RotateTest extends Activity implements OnClickListener{

	private Button ratateButton;
	private ImageView rotateImg;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO 自动生成的方法存根
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_rotate_anime_test);
		ratateButton=(Button)findViewById(R.id.rotate_button);
		rotateImg=(ImageView)findViewById(R.id.rotate_img);
		ratateButton.setOnClickListener(this);
	}
	
	@Override
	public void onClick(View v) {
		// TODO 自动生成的方法存根
		switch (v.getId()) {
		case R.id.rotate_button:
			RotateAnimation animation=new RotateAnimation(0,720,Animation.RELATIVE_TO_SELF,0.5f,Animation.RELATIVE_TO_SELF,0.5f);
			animation.setFillAfter(true);	//保证动画终止时停留在最后一帧
			rotateImg.startAnimation(animation);
			animation.setDuration(3000);
			break;
		default:
			break;
		}
	}

}
