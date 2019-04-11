package 交互;

import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JPanel;

class 设置 extends JPanel{
	/**
	 * 
	 */
	private static final long serialVersionUID = -9142720251872028777L;

	public 设置() {
		setLayout(new GridLayout(0,1));
		JButton[] buttons=new JButton[2];
		buttons[0]=new JButton("音乐");
		buttons[1]=new JButton("音效");
		
		for (int i = 0; i < buttons.length; i++) {
			buttons[i].setSize(10, 10);
			add(buttons[i]);
		}
		
//		setVisible(true);
//		repaint();

	}
}