import java.util.Scanner;

public class Task5_4{
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		System.out.println("Please enter the integer number:");
		int number=input.nextInt();
		reverse(number);
	}
	public static void reverse(int n){
		int b;
		int time=0;
		while(n!=0){
		n=n/10;
		time++;
		}
		
	}
}