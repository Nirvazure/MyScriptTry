package 交互;

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JApplet;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class 开始菜单 extends JApplet{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1000000000;

	public 开始菜单() {
		// TODO 自动生成的构造函数存根
		add(new Start());
	}
	
//	public static void main(String[] args) {
//		JPanel aJPanel=new Start();
//		
//	}
}

class Start extends JPanel{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 7007542101155720556L;
	
	Icon newGameIcon=new ImageIcon("交互/image/普通球.png");
	Icon loadGameIcon=new ImageIcon("交互/image/怪兽球02.png");
	Icon settingIcon=new ImageIcon("交互/image/怪兽球03.png");
	Icon exitIcon=new ImageIcon("交互/image/怪兽球04.png");
	ImageIcon logo=new ImageIcon("交互/image/logo.png");
	
	public Start() {
		// TODO 自动生成的构造函数存根
		
		
//		setLocation(2000, 2000);
		setBackground(new Color(0));
		setLayout(new FlowLayout());
//		setSize(1200, 400);
		JButton newGameButton=new JButton("     开始新的冒险     ",newGameIcon);
		JButton loadGameButton=new JButton("     载入冒险进度     ",loadGameIcon);
		JButton settingGameButton=new JButton("           设置                 ",settingIcon);
		JButton exitGameButton=new JButton("       离开游戏            ",exitIcon);
		Container buttons=new Container();
		
		add(new JLabel(logo));
		
		buttons.setLayout(new GridLayout(0,4,5,0));
//		buttons.setSize(80, 100);
		
		newGameButton.setBackground(new Color(0));
		loadGameButton.setBackground(new Color(0));
		settingGameButton.setBackground(new Color(0));
		exitGameButton.setBackground(new Color(0));
		
		buttons.add(newGameButton);
		buttons.add(loadGameButton);
		buttons.add(settingGameButton);
		buttons.add(exitGameButton);
		add(buttons);
		
		newGameButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				
			}
		});
		
		loadGameButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				
			}
		});
		
		settingGameButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				removeAll();
				add(new 设置());
//				setVisible(true);
				repaint();
			}
		});
		
		exitGameButton.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				System.exit(0);
			}
		});
		
		setVisible(true);
		
	}
	
	public void repaint() {

//		cc.vicp.hrmthw.Tools.waitTime(1000);
		
		super.repaint();
	}
	
}