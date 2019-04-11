package com.lfr.firstcodetest;

import com.example.firstcodetest.R;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class SmsTest extends Activity implements OnClickListener {

	private Button callToMum;
	private Button callToDad;
	private Button callToGrandParent;
	private Button dialBox;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO 自动生成的方法存根
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_sms);
		callToMum=(Button)findViewById(R.id.call_to_mum);
		callToDad=(Button)findViewById(R.id.call_to_dad);
		callToGrandParent=(Button)findViewById(R.id.call_to_grandParent);
		dialBox=(Button)findViewById(R.id.dial);
		callToMum.setOnClickListener(this);
		callToDad.setOnClickListener(this);
		callToGrandParent.setOnClickListener(this);
		dialBox.setOnClickListener(this);
	}
	
	@Override
	public void onClick(View v) {
		// TODO 自动生成的方法存根
		switch (v.getId()) {
		case R.id.call_to_mum:
			Intent intent=new Intent(Intent.ACTION_CALL,Uri.parse("tel:15209182989"));
			startActivity(intent);
			break;
		case R.id.call_to_dad:
			Intent intent2=new Intent(Intent.ACTION_CALL,Uri.parse("tel:15291450538"));
			startActivity(intent2);
			break;
		case R.id.call_to_grandParent:
			Intent intent3=new Intent(Intent.ACTION_CALL,Uri.parse("tel:15103064792"));
			startActivity(intent3);
			break;
		case R.id.dial:	//有问题这里
			Intent intent4=new Intent(Intent.ACTION_DIAL);
			startActivity(intent4);
			break;
		default:
			break;
		}
	}

}
