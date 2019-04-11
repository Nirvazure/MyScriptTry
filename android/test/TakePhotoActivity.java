package com.lfr.firstcodetest;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import com.example.firstcodetest.R;

import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

public class TakePhotoActivity extends Activity implements OnClickListener{

	public static final int TAKE_PHOTO=1;
	public static final int CROP_PHOTO=2;

	private Button chooseFromAlbum;
	private Button takePhoto;
	private ImageView picture;
	private Uri imgUri;



	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_take_photo);

		takePhoto=(Button)findViewById(R.id.take_photo);
		chooseFromAlbum=(Button)findViewById(R.id.choose_from_album);
		picture=(ImageView)findViewById(R.id.picture);

		takePhoto.setOnClickListener(this);
		chooseFromAlbum.setOnClickListener(this);
	}

	@Override
	public void onClick(View v) {
		// TODO 自动生成的方法存根
		File outputImage;
		switch (v.getId()) {
		case R.id.take_photo:
			outputImage=new File(Environment.getExternalStorageDirectory(),"tempImage.jpg");	//如何不存在根目录下，如何使起名字灵活一点
			try {
				if (outputImage.exists()) {
					outputImage.delete();
				}
				outputImage.createNewFile();
			} catch (IOException e) {
				// TODO: handle exception
				e.printStackTrace();
			}
			imgUri=Uri.fromFile(outputImage);
			Intent intent=new Intent("android.media.action.IMAGE_CAPTURE");
			intent.putExtra(MediaStore.EXTRA_OUTPUT, imgUri);
			startActivityForResult(intent, TAKE_PHOTO);
			break;
		case R.id.choose_from_album:
			outputImage=new File(Environment.getExternalStorageDirectory(),"output_image.jpg");
			try {
				if (outputImage.exists()) {
					outputImage.delete();
				}
				outputImage.createNewFile();
			} catch (IOException e) {
				// TODO: handle exception
				e.printStackTrace();
			}
			imgUri=Uri.fromFile(outputImage);
			Intent intent2=new Intent("android.intent.action.GET_CONTENT");
			intent2.setType("image/*");
			intent2.putExtra("crop", true);
			intent2.putExtra("scale", true);
			intent2.putExtra(MediaStore.EXTRA_OUTPUT, imgUri);
			startActivityForResult(intent2, CROP_PHOTO);
			break;
		default:
			break;
		}
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// TODO 自动生成的方法存根
		switch (requestCode) {
		case TAKE_PHOTO:
			if (resultCode==RESULT_OK) {
				Intent intent=new Intent("com.android.camera.action.CROP");
				intent.setDataAndType(imgUri, "image/*");	//不懂
				intent.putExtra("scale", true);
				intent.putExtra(MediaStore.EXTRA_OUTPUT, imgUri);
				startActivityForResult(intent, CROP_PHOTO);
			}
			break;
		case CROP_PHOTO:
			if (resultCode==RESULT_OK) {
				try {
					Bitmap bitmap=BitmapFactory.decodeStream(getContentResolver().openInputStream(imgUri));
					picture.setImageBitmap(bitmap);
				} catch (FileNotFoundException e) {
					// TODO: handle exception
					e.printStackTrace();
				}
			}
			break;
		default:
			break;
		}
	}

}
