package com;

public class Goods {
	private String name;
	private float price;
	
	public Goods(String _name,float _price){
		name=_name;
		price=_price;
	}
	
	public void setName(String _name) {
		name=_name;
	}
	
	public String getName() {
		return name;
	}
	
	public void  setPrice(float _price) {
		price=_price;
	}
	
	public float getPrice() {
		return price;
	}
}
