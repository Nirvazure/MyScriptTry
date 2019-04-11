public class java3_16{
	public static void main(String[] args){
		char rand;
		
		do{rand = (char)(Math.random()*100);
		}while(rand <= 65&&rand >= 90);
		
		System.out.println(rand);
	}
}