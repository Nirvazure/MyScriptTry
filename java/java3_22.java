import java.util.Scanner;

public class java3_22{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter a point with two coordinates : ");
		float x = input.nextFloat();
		float y = input.nextFloat();
		
		if (Math.pow(x, 2) + Math.pow(y, 2) <= 100) {
			System.out.println("Point ( " + x + "," + y +" ) is in the circle");
		}
		else {
			System.out.println("Point ( " + x + "," + y +" ) is not in the circle");
		}
	}
}