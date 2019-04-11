import java.util.Date;

public class TimeDate{
	public static void main(String[] args) {
		Date date=new Date();
		
		System.out.println("将对象直接输出："+date);
		
		String str1=String.format("全部日期时间信息：%tc%n",date);//%n此处表示换行
		System.out.print(str1);
		
		String str2=String.format("月/日/年格式：%tD%n",date);
		System.out.print(str2);
		
		String str3=String.format("年/月/日格式：%tF%n",date);
		System.out.print(str3);
		
		String str4=String.format("HH:MM;SS PM格式（12时制）：%tr%n",date);
		System.out.print(str4);
		
		System.out.printf("HH:MM格式（24时制）:%tR",date);
		
		System.out.printf("HH:MM:SS格式（24时制）:%tT%n",date);
	}
}