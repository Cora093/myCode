import java.util.Scanner;
public class BubbleSort {
	public static void main(String[] args) {
		//����ð������ ��һ�������С��������
		//1.��������

		//��������
		int[] arr = new int[5];

		//������ֵ
		Scanner sc = new Scanner(System.in);
		int length = arr.length;
		for(int i = 0; i < length; i++){
			System.out.println("�������" + (i + 1) + "�����֣�һ��" + length + "����");
			arr[i] = sc.nextInt();
		}

		//2.ð������
		for(int i = 0; i < length - 1; i++) {
			for(int j = 0; j < length - 1 - i; j++) {
				if(arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}




		//3.������

		for(int i = 0; i < length; i++){
			System.out.println("��" + (i + 1) + "��������" + arr[i] + "��һ��" + length + "����");
		}
	}
}