package com.lfr.firstcodetest;

import com.example.firstcodetest.R;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;

public class WebviewTest extends Activity implements OnClickListener{
	
	private WebView webView;
	private Button goTo;
	private EditText editText;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO 自动生成的方法存根
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_web_test);
		webView=(WebView)findViewById(R.id.web_view);
		goTo=(Button)findViewById(R.id.search);
		editText=(EditText)findViewById(R.id.editText);
		
		webView.getSettings().setJavaScriptEnabled(true);
		webView.setWebViewClient(new WebViewClient(){
			@Override
			public boolean shouldOverrideUrlLoading(WebView view, String url) {
				view.loadUrl(url);	//根据传入的参数再去加载新的网页
				return true;	//表示当前webView可以处理打开新网页的请求，不借助系统浏览器
			}
		});
		webView.loadUrl("http://www.baidu.com");
		goTo.setOnClickListener(this);
	}

	@Override
	public void onClick(View v) {
		// TODO 自动生成的方法存根
		switch (v.getId()) {
		case R.id.search:
			String tempUri=editText.getText().toString();
			webView.loadUrl(tempUri);
			break;
		default:
			break;
		}
	}
	
}
