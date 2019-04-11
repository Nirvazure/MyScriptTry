package cc.vicp.hrmthw;

import java.util.TimerTask;

public class Tools{
	public static void waitTime(long time) {
		java.util.Timer timer=new java.util.Timer();
		timer.schedule(new TimerTask() {
			
			@Override
			public void run() {
				// TODO 自动生成的方法存根
				this.cancel();
			}
		}, time);
	}
}