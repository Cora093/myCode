//演示转义字符的使用

public class ChangeChar{

	//main方法
	public static void main(String[] args){
		System.out.println("北京\t上海\t天津");
		System.out.println("\\n是\n换行符");

		// \r 表示回车 (区别于\n换行)
		System.out.println("我我我我我我我我我我我我\r回车后输出在行首");

		//练习
		System.out.println("书名\t作者\t价格\t销量\n三国\t罗贯中\t120\t1000");
	}
}