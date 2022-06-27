//基本数据类型和字符串的转换

public class StringToBasic {

	public static void main(String[] args) {
		
		//基本数据类型->String
		//用加号连接

		int n1 = 100;
		float f1 = 3.14f;
		double d1 = 4.5;
		boolean b1 = true;

		String s1 = n1 + "";	
		String s2 = f1 + "";	
		String s3 = d1 + "";	
		String s4 = b1 + "";	

		System.out.println(s1 + " " + s2 + " " + s3 + " " + s4);

		//string->基本数据类型
		//使用基本数据类型对应的包装类中的parse方法，把string转换成基本数据类型

		int n2 = Integer.parseInt(s1);
		double d2 = Double.parseDouble(s1);
		//以此类推

		System.out.println(n2);//100
		System.out.println(d2);//100.0

		//怎么把字符串转成字符char->含义是指把字符串的第一个字符得到
		System.out.println(s4.charAt(0));//t
		


	}
}