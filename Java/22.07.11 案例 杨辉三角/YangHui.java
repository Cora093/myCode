import java.util.Scanner;
public class YangHui {
	public static void main(String[] args) {
		//使用二维数组打印杨辉三角(n行)
		//1
		//1 1
		//1 2 1
		//1 3 3 1
		System.out.println("请输入要打印的行数：");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();						//输入行数

		int[][] arr = new int[n][];
		for(int i = 0; i < arr.length; i++) {
			arr[i] = new int[i+1];						//杨辉三角第n行有n个数
			for(int j = 0; j < arr[i].length; j++) {		
				if(j == 0 || j == arr[i].length - 1) {	//每行首尾都是1
					arr[i][j] = 1;					
				}
				else {
					arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
				}
			}
		}

		for(int i = 0; i < arr.length; i++) {					//输出数组
			for(int j = 0; j < arr[i].length; j++) {	
				System.out.print(arr[i][j] + "\t");
			}
			System.out.println();
		}
	}
}