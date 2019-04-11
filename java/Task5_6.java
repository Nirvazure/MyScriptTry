import java.util.Scanner;

public class Task5_6{
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		System.out.println("Please enter the length:");
		int n=input.nextInt();
		display(n);
	}
	public static void display(int n){
		for(int j=1;j<=n;j++){
			System.out.print("  ");
			for(int i=1;i<=n-j;i++)
				System.out.print(" ");
			for(int i=j;i>=1;i--)
				System.out.print(i);
			System.out.println();
		}
	}
}