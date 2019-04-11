import java.util.Scanner;/*finished perfectly*/

public class Task3_4{
	public static void main(String[] args) {
		int i=0;
		while(i==0){
			int number1=(int)(Math.random()*100);
			int number2=(int)(Math.random()*100);
			System.out.println("What is"+number1+"+"+number2+"?");
			System.out.println("Please enter the result");
			Scanner input=new Scanner(System.in);
			int answer=input.nextInt();
			if(number1+number2==answer)
				System.out.println("Your answer is right");
			else{
				System.out.println("your answer is wrong!");
				System.out.println("The ture answer is"+(number1+number2));
				}			
			System.out.println("If you want to continue Please enter 0");
			System.out.println("If you want to finish Please enter 1");
			int count=input.nextInt();
			i=i+count;
			if(i==1) System.out.println("The program finished!");
		}
	}
}