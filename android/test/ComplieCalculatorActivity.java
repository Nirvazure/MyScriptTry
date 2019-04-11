package com.lfr.firstcodetest;

import com.example.firstcodetest.R;
import com.lfr.firstcodetestUtil.CompCalculator;

import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.app.Activity;

public class ComplieCalculatorActivity extends Activity implements OnClickListener{

	private CompCalculator calculator;
	
	private Button num1;
	private Button num2;
	private Button num3;
	private Button num4;
	private Button num5;
	private Button num6;
	private Button num7;
	private Button num8;
	private Button num9;
	private Button num0;
	private Button plus;
	private Button sub;
	private Button multiply;
	private Button devide;
	private Button leftBracket;
	private Button rightBracket;
	private Button dot;
	private Button clear;
	private Button result;
	
	private TextView resultTextView;
	
	private StringBuilder stringBuilder;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_complie_calculator);
		
		stringBuilder=new StringBuilder();
		
		resultTextView=(TextView)findViewById(R.id.result_text);
		num0=(Button)findViewById(R.id.num0);
		num1=(Button)findViewById(R.id.num1);
		num2=(Button)findViewById(R.id.num2);
		num3=(Button)findViewById(R.id.num3);
		num4=(Button)findViewById(R.id.num4);
		num5=(Button)findViewById(R.id.num5);
		num6=(Button)findViewById(R.id.num6);
		num7=(Button)findViewById(R.id.num7);
		num8=(Button)findViewById(R.id.num8);
		num9=(Button)findViewById(R.id.num9);
		leftBracket=(Button)findViewById(R.id.left_bracket);
		rightBracket=(Button)findViewById(R.id.right_bracket);
		plus=(Button)findViewById(R.id.plus);
		sub=(Button)findViewById(R.id.sub);
		devide=(Button)findViewById(R.id.devide);
		multiply=(Button)findViewById(R.id.multiply);
		dot=(Button)findViewById(R.id.dot);
		result=(Button)findViewById(R.id.draw_result);
		clear=(Button)findViewById(R.id.clear);
		num0.setOnClickListener(this);
		num1.setOnClickListener(this);
		num2.setOnClickListener(this);
		num3.setOnClickListener(this);
		num4.setOnClickListener(this);
		num5.setOnClickListener(this);
		num6.setOnClickListener(this);
		num7.setOnClickListener(this);
		num8.setOnClickListener(this);
		num9.setOnClickListener(this);
		leftBracket.setOnClickListener(this);
		rightBracket.setOnClickListener(this);
		result.setOnClickListener(this);
		clear.setOnClickListener(this);
		dot.setOnClickListener(this);
		plus.setOnClickListener(this);
		sub.setOnClickListener(this);
		multiply.setOnClickListener(this);
		devide.setOnClickListener(this);
	}

	@Override
	public void onClick(View view) {
		// TODO 自动生成的方法存根
		switch (view.getId()) {
		case R.id.num1:
			stringBuilder.append("1");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num2:
			stringBuilder.append("2");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num3:
			stringBuilder.append("3");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num4:
			stringBuilder.append("4");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num5:
			stringBuilder.append("5");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num6:
			stringBuilder.append("6");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num7:
			stringBuilder.append("7");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num8:
			stringBuilder.append("8");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num9:
			stringBuilder.append("9");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.num0:
			stringBuilder.append("0");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.clear:
			stringBuilder.delete(0, stringBuilder.length());
			resultTextView.setText("");
			break;
		case R.id.left_bracket:
			stringBuilder.append("(");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.right_bracket:
			stringBuilder.append(")");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.dot:
			stringBuilder.append(".");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.plus:
			stringBuilder.append("+");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.sub:
			stringBuilder.append("-");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.multiply:
			stringBuilder.append("*");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.devide:
			stringBuilder.append("/");
			resultTextView.setText(stringBuilder.toString());
			break;
		case R.id.draw_result:
			double temp=calculator.Calculator(stringBuilder.toString());
			stringBuilder.append("=");
			stringBuilder.append(temp);
			resultTextView.setText(stringBuilder.toString());
			break;
		default:
			break;
		}
	}

}
