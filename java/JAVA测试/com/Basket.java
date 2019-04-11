package com;

import java.util.ArrayList;

public class Basket {
	
	private ArrayList<Goods> goodsList=new ArrayList<>();
	
	public void addGoods(Goods goods) {
		goodsList.add(goods);
	}
	
	public ArrayList<Goods> getAllGoods() {
		return goodsList;
	}
	
	public boolean isEmpty() {
		return goodsList.isEmpty();
	}
	
	public void clear() {
		goodsList.clear();
	}
	
	public float getTotalprice() {
		float total=0;
		for (int i = 0; i < goodsList.size(); i++) {
			Goods tempGoods=goodsList.get(i);
			total=total+tempGoods.getPrice();
		}
		return total;
	}
	
}
