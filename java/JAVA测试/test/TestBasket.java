package test;

import com.Basket;
import com.Goods;

import junit.framework.TestCase;

public class TestBasket extends TestCase{
	
	Basket testBasket;
	
	public void testGetAllGoods() {
		testBasket=new Basket();
		testBasket.addGoods(new Goods("apple", 1));
		testBasket.addGoods(new Goods("orange", 2));
		assertEquals(3, (testBasket.getAllGoods().get(0).getPrice()+testBasket.getAllGoods().get(1).getPrice()), 10e-9);
		
		}
	
	public void testAddGoods(){
		testBasket=new Basket();
		assertTrue(testBasket.isEmpty());
		testBasket.addGoods(new Goods("apple", 12));
		assertFalse(testBasket.isEmpty());
	}
	
	public void testIsEmpty() {
		testBasket=new Basket();
		testBasket.clear();
		assertTrue(testBasket.isEmpty());
		testBasket.addGoods(new Goods("apple", 12));
		assertFalse(testBasket.isEmpty());
	}
	
	public void testClear() {
		testBasket=new Basket();
		testBasket.addGoods(new Goods("apple", 12));
		assertFalse(testBasket.isEmpty());
		testBasket.clear();
		assertTrue(testBasket.isEmpty());
	}

	public void testGetTotalPrice() {
		testBasket=new Basket();
		testBasket.addGoods(new Goods("apple", 1));
		testBasket.addGoods(new Goods("orange", 2));
		assertEquals(3, testBasket.getTotalprice(),10e-9);
	}
}
