import java.util.Scanner;
public class BubbleSort {
	public static void main(String[] args) {
		//利用冒泡排序 对一个数组从小到大排序
		//1.输入数组

		//创建数组
		int[] arr = new int[5];

		//输入数值
		Scanner sc = new Scanner(System.in);
		int length = arr.length;
		for(int i = 0; i < length; i++){
			System.out.println("请输入第" + (i + 1) + "个数字（一共" + length + "个）");
			arr[i] = sc.nextInt();
		}

		//2.冒泡排序
		for(int i = 0; i < length - 1; i++) {
			for(int j = 0; j < length - 1 - i; j++) {
				if(arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}




		//3.输出结果

		for(int i = 0; i < length; i++){
			System.out.println("第" + (i + 1) + "个数字是" + arr[i] + "（一共" + length + "个）");
		}
	}
}