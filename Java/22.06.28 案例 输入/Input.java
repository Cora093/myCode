import java.util.Scanner;//表示把java.util下的Scanner类导入
public class Input {
	public static void main(String[] args) {
		//演示接受用户的输入
		//步骤
		//1.引入Scanner类所在的包
		//2.创建Scanner对象
		Scanner sc = new Scanner(System.in);
		//3.接受用户的输入(使用相关的方法)
		System.out.println("请输入名字");
		String name = sc.next();//接收输入的String
		System.out.println("请输入年龄");
		int age = sc.nextInt();	//接收输入的int	
		System.out.println("请输入薪水");
		double salary = sc.nextDouble();//接收输入的double

		System.out.println("信息如下：");
		System.out.println("名字：" + name + "\t" + "年龄：" + age + "\t" 
			+ "薪水：" + salary);
	}
}