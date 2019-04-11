package cc.vicp.hrmthw;
/**
 * 多功能单向链表，任意个数据域，每个数据域支持任意基本数据类型<br>
 * （完成）(bug)
 * @author hrmthw 
 * @version 1.05
 * @since 2013-03-13
 */


/**
 * 链表节点
 * @author hrmthw
 * 
 */


public class ChainList{
	class Node{
		Object[] x;
		Node next;
		Node(Node next,Object... xValue) {
			this.x=xValue;
			this.next=next;
		}
	}
	private Node thisNode;

	private int elemNum;
	
	private long length=0;
	
	/**
	 * 创建新链表
	 * @param n 指定每个节点数据域个数
	 */
//	public ChainList(Object... value) {
//		// TODO 自动生成的构造函数存根
//		thisNode=new Node(new Node(null,value),0);
//		elemNum=value.length;
//		this.length++;
//	}
	public ChainList(int n) {
		// TODO 自动生成的构造函数存根
		thisNode=new Node(null,0);	
		elemNum=n;
	}
	
	/**
	 * 内部扫描器,辅助下面的方法,使tmpNomde.next指向第num个节点
	 * @param num
	 * @return
	 */
	private Node scan(long num) {
		if(num>this.length)throw new IllegalAccessError("扫描目标节点不存在！");
		Node tmpNode=this.thisNode;
		for(long i=1;i<=num;i++) {
			tmpNode=tmpNode.next;
		}
		return tmpNode;
	}
	
	/**
	 * 获取链表长度
	 * @return 长度
	 */
	public long getLength() {
		return this.length;
	}
	
	/**
	 * 获取节点值
	 * @param num
	 * @return 第num个节点的第n个值
	 */
	public Object[] getData(long num) {
		return this.scan(num).x;
	}
	
	public Object getData(long num,int n) {
		if(n>this.elemNum)throw new IllegalAccessError("读取目标超出链表横向范围！");
		return this.scan(num).x[n-1];
	}

	
	public void setData(int num,Object... x) {
		if(num>this.getLength())throw new IllegalAccessError("修改目标节点超出既有链表范围，请尝试添加节点。");
		Node tmpNode=scan(num);
		if(x.length==this.getLength()) { 
			tmpNode.x=x;
		}else {
			for (int i = 0; i < x.length; i++) {
				tmpNode.x[i] = x[i];
			}
		}
	}
	/**
	 * 向链表末端添加新节点
	 * @param x 添加值（可以多个）
	 */
	public void add(Object... x) {
		if(x.length>elemNum)throw new IllegalAccessError("添加数据超出链表横向范围！");
		Node tmpNode=this.scan(getLength());
		tmpNode.next=new Node(null,x);
		this.length++;
	}
	
	/**
	 * 删除目标节点
	 * @param num
	 */
	public void del(long num) {
		if(num>this.length)throw new NoSuchFieldError("删除目标节点不存在！");
		Node tmpNode=scan(num-1);
		tmpNode.next=tmpNode.next.next;
		this.length--;
	}

	/**
	 * 插入节点
	 * @param num 插入节点位置
	 * @param x
	 */
	public void insert(long num,Object... x) {
		if(num>this.getLength())throw new IllegalAccessError("插入目标节点超出既有链表范围，请尝试添加节点。");
		Node tmpNode=scan(num-1);
		tmpNode.next=new Node(tmpNode.next,x);
		this.length++;
	}

}