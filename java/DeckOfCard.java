public class DeckOfCard{
	//用GUI改写
	public static void main(String[] args) {
		int[] deck=new int[52];
		String[] suits={"Spades","Heart","Diamond","Club"};
		String[] ranks={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
		initializeCard(deck);
		shuffleTheCard(deck);
		//the next statement is to display the first four cards
		for(int i=0;i<4;i++){
			String suit=suits[deck[i]/13];
			String rank=ranks[deck[i]%13];
			System.out.println("Card number"+deck[i]+":	"+rank+"	of	"+suit);
		}
	}
	
	public static void initializeCard(int [] array){
		for(int i=0;i<array.length;i++)
			array[i]=i;
	}
	
	public static void shuffleTheCard(int [] array){
		for(int i=0;i<array.length;i++){
			int index=(int)(Math.random()*array.length);
			int temp=array[i];
			array[i]=array[index];
			array[index]=temp;
		}
	}
}