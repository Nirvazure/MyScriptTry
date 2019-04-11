import java.util.Scanner;/*finished*/

public class Task3_22{
	public static void main(String[] args) {
		final int R=10;
		Scanner input=new Scanner(System.in);
		for(int i=0;i<10;i++){
		System.out.println("Enter a point with two coordinates:");
		float x=input.nextFloat();
		float y=input.nextFloat();
		int d=(int)Math.sqrt(Math.pow(x,2)+Math.pow(y,2));
		if(d<=R) System.out.printf("Point(%3.1f,%3.1f)is in the circle",x,y);
		else if(d>R) System.out.printf("Point(%3.1f,%3.1f)is not in the circle",x,y);
		}
	}
}