//���һ��n��Ŀ��Ľ�����
//    *
//   * *
//  *   *
// *     *
//*********
public class Stars {
	public static void main(String[] args) {
		int totalLevel = 9;
		for(int i = 1;i <= totalLevel;i++){
			//����ո�
			for(int k = totalLevel - i;k > 0;k--){
				System.out.print(" ");
			}
			//���*
			for(int j = 1;j <= 2 * i - 1;j++){
				if(j == 1 || j==(2 * i - 1) || i == totalLevel){
					System.out.print("*");
				} else {
					System.out.print(" ");
				}
			}
			//ÿ�����һ�� ����
			System.out.println("");
		}
	}
}