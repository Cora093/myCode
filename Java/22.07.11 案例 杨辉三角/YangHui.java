import java.util.Scanner;
public class YangHui {
	public static void main(String[] args) {
		//ʹ�ö�ά�����ӡ�������(n��)
		//1
		//1 1
		//1 2 1
		//1 3 3 1
		System.out.println("������Ҫ��ӡ��������");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();						//��������

		int[][] arr = new int[n][];
		for(int i = 0; i < arr.length; i++) {
			arr[i] = new int[i+1];						//������ǵ�n����n����
			for(int j = 0; j < arr[i].length; j++) {		
				if(j == 0 || j == arr[i].length - 1) {	//ÿ����β����1
					arr[i][j] = 1;					
				}
				else {
					arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
				}
			}
		}

		for(int i = 0; i < arr.length; i++) {					//�������
			for(int j = 0; j < arr[i].length; j++) {	
				System.out.print(arr[i][j] + "\t");
			}
			System.out.println();
		}
	}
}