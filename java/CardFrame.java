import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.UIManager;

@SuppressWarnings("serial")
public class CardFrame extends JFrame{
	
	public CardFrame(){
		
		super();
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		}catch(Exception ex){
			ex.printStackTrace();
		}
		
		final CardLayout card=new CardLayout(5,5);
		final JPanel pane=new JPanel(card);
		JPanel p=new JPanel();

		JButton b_1=new JButton("1");
		JButton b_2=new JButton("2");
		JButton b_3=new JButton("3");
		JButton button_1=new JButton("上一步");
		JButton button_2=new JButton("下一步");
		
		//b_1.setMargin(new Insets(2, 2, 2, 2));
		//b_2.setMargin(new Insets(2, 2, 2, 2));
		b_3.setMargin(new Insets(2, 2, 2, 2));
		
		p.add(button_1);
		p.add(b_1);
		p.add(b_2);
		p.add(b_3);
		p.add(button_2);
		
		JPanel p_1=new JPanel();
		JPanel p_2=new JPanel();
		JPanel p_3=new JPanel();
		
		p_1.setBackground(Color.RED);
		p_2.setBackground(Color.BLUE);
		p_3.setBackground(Color.GREEN);
		
		p_1.add(new JLabel("panel_1"));
		p_2.add(new JLabel("panel_2"));
		p_3.add(new JLabel("panel_3"));
		
		pane.add(p_1, "p1");
		pane.add(p_2, "p2");
		pane.add(p_3, "p3");
		
		button_1.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				card.previous(pane);
			}
		});
		
		button_2.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e){
				card.next(pane);
			}
		});
		
		b_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				card.show(pane, "p1");
			}
		});
		
		b_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				card.show(pane, "p2");
			}
		});
		
		b_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				card.show(pane, "p3");
			}
		});
		
		this.setLocationRelativeTo(null);
		this.getContentPane().add(pane);
		this.getContentPane().add(p,BorderLayout.SOUTH);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(300,200);
		this.setVisible(true);
	}
	
	public static void main(String[] args) {
		new CardFrame();
	}
}