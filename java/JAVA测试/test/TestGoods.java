package test;

import com.Goods;

import junit.framework.TestCase;

public class TestGoods extends TestCase{
	
	Goods testGoods;
	
	public void testConstruct() {
		testGoods=new Goods("apple", 12);
		assertEquals("apple", testGoods.getName());
		assertEquals(12, testGoods.getPrice(), 10e-9);
		testGoods=new Goods("orange", 13);
		assertEquals("orange", testGoods.getName());
		assertEquals(13, testGoods.getPrice(), 10e-9);
	}

	public void testGetName() {
		testGoods=new Goods("apple", 12);
		assertEquals("apple", testGoods.getName());
	}
	
	public void testSetName() {
		testGoods=new Goods("apple", 12);
		assertEquals("apple", testGoods.getName());
		testGoods.setName("orange");
		assertEquals("orange", testGoods.getName());
	}
	
	public void testGetPrice() {
		testGoods=new Goods("apple", 12);
		assertEquals(12, testGoods.getPrice(), 10e-9);
	}
	
	public void testSetPrice() {
		testGoods=new Goods("apple", 12);
		assertEquals(12, testGoods.getPrice(), 10e-9);
		testGoods.setPrice(13);
		assertEquals(13, testGoods.getPrice(), 10e-9);
	}
	

}
