import java.util.Scanner;

public class Task5_1{
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		System.out.println("Please enter the integer number:");
		for(int i=0;i<10;i++){
		int number=input.nextInt();
		System.out.println(getPentagonalNumber(number));
		}
	}
	public static int getPentagonalNumber(int n){
		return n*(3*n-1)/2;
	}
}