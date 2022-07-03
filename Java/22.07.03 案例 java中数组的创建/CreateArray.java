

public class CreateArray {
	public static void main(String[] args) {
		//创建一个大小为5的double数组
		//第一种方式：直接new
		double[] score1 = new double[5];

		//第二种方式：先声明，再用new分配空间
		double[] score2;
		score2 = new double[5];

		//第三种方式：静态初始化
		double[] score3 = {1, 2.3, 4, 88, 99};
		//可用length方法获取数组长度
		System.out.println(score3.length);
	}
}