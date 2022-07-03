//输出一个n层的空心金字塔
//    *
//   * *
//  *   *
// *     *
//*********
public class Stars {
	public static void main(String[] args) {
		int totalLevel = 9;
		for(int i = 1;i <= totalLevel;i++){
			//输出空格
			for(int k = totalLevel - i;k > 0;k--){
				System.out.print(" ");
			}
			//输出*
			for(int j = 1;j <= 2 * i - 1;j++){
				if(j == 1 || j==(2 * i - 1) || i == totalLevel){
					System.out.print("*");
				} else {
					System.out.print(" ");
				}
			}
			//每输出完一行 换行
			System.out.println("");
		}
	}
}