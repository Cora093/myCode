
class arr {
	static void show(int[] arr1,int[] arr2){
		System.out.println("arr1:");
		for(int i = 0;i < arr1.length;i++){
			System.out.print(arr1[i] + " ");
		}
		System.out.println();
		
		System.out.println("arr2:");
		for(int i = 0;i < arr2.length;i++){
			System.out.print(arr2[i] + " ");
		}
		System.out.println();
	}

}

public class ArrayDetail {
	public static void main(String[] args) {
		//java������ĸ�ֵ�� ���ô���/��ַ����
		int[] arr1 = {1, 3, 5};
		int[] arr2 = arr1;

		//arr1��arr2���õ�ַ

		arr.show(arr1, arr2);

		arr2[0] = 6;

		arr.show(arr1, arr2);

		arr1[1] = 8;

		arr.show(arr1,arr2);

	}
}

