import java.util.Scanner;/*finished*/

public class Task3_26{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		for(int i=0;i<10;i++){
		System.out.println("Please enter an integer number:");
		int number=input.nextInt();
		
			System.out.println("Is"+number+"divisible by 5 and 6");
			if((number%5==0)&&(number%6==0))
				System.out.println("ture");
			else System.out.println("false");
		
		
			System.out.println("Is"+number+"divisible by 5 or 6");
		
			if((number%5==0)^(number%6==0))
				System.out.println("ture");
			else System.out.println("false");
		
			System.out.println("Is"+number+"divisible by neigher 5 and 6");
			if((number%5!=0)&&(number%6!=0))
				System.out.println("ture");
			else System.out.println("false");
		}
	}
}