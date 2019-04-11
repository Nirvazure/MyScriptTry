import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

public class DrawArcs extends JFrame{	
 
	/**
	 * @since 2013-05-15
	 */
	private static final long serialVersionUID = 3606434704799462733L;

	final int SLOW=50,MEDIUM=20,FAST=3,CRASY=0;
	final int CLOCKWISE=-1,ANTICLOCKWISE=1;
	JButton switcher=new JButton("ON");
	JButton speed=new JButton("SLOW");
	JButton direction=new JButton("CLOCKWISE");
	boolean onoff=false;
	int delay=100;
	int ddelay=CLOCKWISE;
	
	public DrawArcs(){
		setTitle("风扇模拟");
		setLayout(new BorderLayout());
		ArcsPanel arcsPanel=new ArcsPanel();
		add(arcsPanel);
		Container buttons = new Container();
		buttons.setLayout(new GridLayout(1,3,20,0));
		
		
		direction.addActionListener(arcsPanel.directionAction);
		direction.addMouseListener(arcsPanel.dirListener);
		switcher.addActionListener(arcsPanel.switcherAction);
		speed.addActionListener(arcsPanel.speedAction);
		speed.addMouseWheelListener(arcsPanel.speedListener);
		
		buttons.add(direction);
		buttons.add(switcher);
		buttons.add(speed);
		
		add(buttons,BorderLayout.SOUTH);
	}
	
	public static void main(String[] args) {
		DrawArcs frame=new DrawArcs();
		frame.setSize(450, 500);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ArcsPanel extends JPanel{
		/**
		 * @since 2013-05-15
		 */
		private static final long serialVersionUID = -9021205968542807642L;
		Timer timer;
		int angle=0;

		public ArcsPanel() {
			setSize(200, 200);
			timer=new Timer(delay,task);				
		}
		
		
		ActionListener directionAction=new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(ddelay==CLOCKWISE){
					direction.setText("ANTICLOCKWISE");
					ddelay=ANTICLOCKWISE;
				}else{
					direction.setText("CLOCKWISE");
					ddelay=CLOCKWISE;
				}
			}
		};
		ActionListener switcherAction=new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!onoff) {
					timer.start();
					switcher.setText("OFF");
					onoff=true;
				}else {
					timer.stop();
					switcher.setText("ON");
					onoff=false;
				}
				
			}
		};
		ActionListener speedAction=new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				switch (delay) {
				case SLOW:
					delay=MEDIUM;
					timer.setDelay(delay);
					speed.setText("MEDIUM");
					break;
				case MEDIUM:
					delay=FAST;
					timer.setDelay(delay);
					speed.setText("FAST");
					break;
				case FAST:
					delay=CRASY;
					timer.setDelay(delay);
					speed.setText("CRASY");
					break;
				case CRASY:
					delay=SLOW;
					timer.setDelay(delay);
					speed.setText("SLOW");
				default:
					delay=SLOW;
					speed.setText("SLOW");
					break;
				}
				
			}
		};
		MouseListener dirListener=new MouseListener() {
			
			@Override
			public void mouseReleased(MouseEvent arg0) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void mousePressed(MouseEvent arg0) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void mouseExited(MouseEvent arg0) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void mouseEntered(MouseEvent arg0) {
				// TODO 自动生成的方法存根
				
			}
			
			@Override
			public void mouseClicked(MouseEvent arg0) {
				// TODO 自动生成的方法存根
				if(arg0.getButton()==MouseEvent.BUTTON1){
					direction.setText("ANTICLOCKWISE");
					ddelay=ANTICLOCKWISE;
				}
				if (arg0.getButton()==MouseEvent.BUTTON3) {
					direction.setText("CLOCKWISE");
					ddelay=CLOCKWISE;
				}
			}
		};

		MouseWheelListener speedListener=new MouseWheelListener() {
			
			@Override
			public void mouseWheelMoved(MouseWheelEvent arg0) {
				if(arg0.getButton()==MouseWheelEvent.WHEEL_UNIT_SCROLL){
					switch (delay) {
					case SLOW:
						delay=MEDIUM;
						timer.setDelay(delay);
						speed.setText("MEDIUM");
						break;
					case MEDIUM:
						delay=FAST;
						timer.setDelay(delay);
						speed.setText("FAST");
						break;
					case FAST:
						delay=CRASY;
						timer.setDelay(delay);
						speed.setText("CRASY");
						break;
					case CRASY:
						delay=SLOW;
						timer.setDelay(delay);
						speed.setText("SLOW");
					default:
						delay=SLOW;
						speed.setText("SLOW");
						break;
					}
				}
			}
		};
		
		ActionListener task= new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				repaint();
				angle=angle+ddelay*2;
				}
		};
		
		protected void paintComponent(Graphics image){
			super.paintComponent(image);
			
			int xCenter=getWidth()/2;
			int yCenter=getHeight()/2;
			int radius=(int)(Math.min(getWidth(), getHeight())*0.4);
			
			int x=xCenter-radius;
			int y=yCenter-radius;
			
			image.fillArc(x, y, radius*2, radius*2, 0+angle, 30);
			image.fillArc(x, y, radius*2, radius*2, 90+angle, 30);
			image.fillArc(x, y, radius*2, radius*2, 180+angle, 30);
			image.fillArc(x, y, radius*2, radius*2, 270+angle, 30);
			
		}
	}
}
