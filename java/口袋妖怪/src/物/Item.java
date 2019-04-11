package 物;

import java.awt.Image;


class Monster{
	
	public enum 属性 {												//枚举类型属性
		一般,幽灵,电,飞行,超能,岩石,水,光,火,草,恶,龙,地面,格斗
	}
	
	public enum 状态{
		 烧伤,麻痹,中毒,沉睡
	}
	
	class ability{
		属性 属性;
		String 名字;
		int 技能使用次数;
		int 最大技能使用次数;
		int 命中;
		int 威力;
		String 说明;
	}
	
	属性 属性[];
	状态 状态[];
	int attack;
	int defense;
	int sAttack;
	int fortune;
	int dex;//敏捷
	int health;
	int healthLimit;
	int exp;
	ability ability[];
	
	public Monster() {
		// TODO 自动生成的构造函数存根
	}

	/**
	 * @since 1.01
	 * @param 回复量
	 */
	public void 治疗(int 回复量) {
		if(回复量+health>healthLimit){
			health=healthLimit;
		}
		else {
			health=health+回复量;
		}
	}
	public void  治疗() {
		health=healthLimit;
		for (int i = 0; i < ability.length; i++) {
			ability[i].技能使用次数=ability[i].最大技能使用次数;
		}
	}
}


class player{
	char sex;//male or female
	int direction;//east west north south
	public class 物品{
		final static int 怪兽球=0,珍贵物品=1,道具=2,树果=3,秘笈=4;
		int id;
		String name;
		int 类;
		long 金钱;
	//	Image icon;
	}
	
	Image[] skin=new Image[4];
	Monster[] pets=new Monster[6];
	物品[] 背包=new 物品[100];
	
	private int xOfLocation;
	private int yOfLocation;
	
	
	public void 移动(){;
	
	}
	
	public void 交互(){;
	//调查面前事物 ，及对话
	}
	
	@SuppressWarnings("unused")
	private int VS(){
		return 0;
	}
}

class NPC{
	//1,野怪为默认NPC
	Monster[] pets=new Monster[6];
}
