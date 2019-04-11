package com.example.touchball;

import android.app.Activity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.LinearLayout;

public class CustomView extends Activity{
	
	public void onCreate(Bundle saveInstanceState) {
		super.onCreate(saveInstanceState);
		setContentView(R.layout.activity_main);
		LinearLayout root=(LinearLayout)findViewById(R.id.root);
		final Drawview drawview=new Drawview(this);
		drawview.setMinimumHeight(500);
		drawview.setMinimumWidth(300);
		drawview.setOnTouchListener(new OnTouchListener() {
			public boolean onTouch(View arg0, MotionEvent event) {
				// TODO 自动生成的方法存根
				drawview.currentX=event.getX();
				drawview.currentY=event.getY();
				drawview.invalidate();
				return true;
			}
		});
		root.addView(drawview);
	}
	
}
