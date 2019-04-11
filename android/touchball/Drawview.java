package com.example.touchball;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;

public class Drawview extends View{
	
	public float currentX=40;
	public float currentY=50;
	
	public Drawview(Context context){
		super(context);
	}
	

	@SuppressLint("DrawAllocation")
	public void onDraw(Canvas canvas) {
		super.onDraw(canvas);
		Paint p=new Paint();
		p.setColor(Color.RED);
		canvas.drawCircle(currentX, currentY, 15, p);
	}
	
}
