package com;

import java.util.Scanner;

public class Store {
	static final Goods[] GOODS={new Goods("Bread", (float) 1.0),new Goods("Cocacola", (float) 1.0),new Goods("Bear", (float) 1.0),new Goods("Pencil", (float) 0.5),new Goods("Notebook", (float) 3.0)};
	static Basket basket=new Basket();
	static final String MESSAGE_HEADER="**********************************************\n/tWelcome to XiaoFang Convenience Store\n**********************************************\n";
	static final String MESSAGE_FOOTER="\n<9> CHECK OUT\n<0> EXIT\n-----------------------------------------------\nPLEASE SELECT THE NUMBER:";

	static void exit(){
		System.exit(0);
	}
	static void checkOut(){
		System.out.println("========== CHECK OUT ==========\n");
		for (int i = 0; i < basket.getAllGoods().size(); i++) {
			System.out.println("<"+(i+1)+"> "+basket.getAllGoods().get(i).getName()+"\t\t"+basket.getAllGoods().get(i).getPrice());		
		}
		System.out.println("===============================\n");
		System.out.println("TOTAL: "+basket.getTotalprice());
		System.out.println("THANKS!");
	}
	static void invalidinput(){
		System.out.println("\n\nINVALID INPUT.PLEASE TRY AGAIN!");
	}
	static void addGoods(int choice){
		basket.addGoods(GOODS[choice-1]);
		System.out.println("YOU HAVE SELECTED ["+GOODS[choice-1].getName()+"], "+GOODS[choice-1].getPrice());
	}
	static void printMenu(){
		System.out.println(MESSAGE_HEADER);
		for (int i = 0; i < GOODS.length; i++) {
			System.out.println("<"+(i+1)+"> "+GOODS[i].getName()+"\t\t"+GOODS[i].getPrice());		
		}
		System.out.println(MESSAGE_FOOTER);
	}

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner input=new Scanner(System.in);
		boolean isContinue=true;
		do {
			printMenu();
			try {
				int choice=input.nextInt();
				if ((choice<6)&&(choice>0)) {
					addGoods(choice);
				}else if (choice==0) {
					exit();
					isContinue=false;
				}else if (choice==9) {
					checkOut();
					input.next();
					basket.clear();
				}else {
					invalidinput();
				}
			} catch (Exception e) {
				invalidinput();
				input.next();
			}
		} while (isContinue);
	}

}
