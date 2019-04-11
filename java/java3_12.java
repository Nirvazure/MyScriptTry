import java.util.Scanner;

public class java3_12{
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter an integer :");
		int num = input.nextInt();
		
		if(num %5 == 0^num %6 == 0)System.out.println(num + " is divisible by 5 or 6, but not both");
		if(num %6 == 0&&num %5 == 0)System.out.println(num + " is divisible by both 5 and 6 ");
		if(num %5 != 0&&num %6 != 0)System.out.println(num + " is not divisible by either 5 or 6");
		
	}
}