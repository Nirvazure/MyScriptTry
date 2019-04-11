import javax.swing.JOptionPane;

public class java3_18{
	public static void main(String[] args){
	String yearString = JOptionPane.showInputDialog("Enter a year :");
	int year = Integer.parseInt(yearString);
	
	System.out.println(year + " is a leap year ?   " + ((year %4 == 0&&year %100 !=0)||(year %400 == 0)));
	}
}