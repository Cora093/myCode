public class MultTable {
	public static void main(String[] args) {
		for(int i = 1;i < 10;i++){
			for(int j = 1;j < 10;j++){
				if(j > i){
					System.out.print("\n");
					break;
				}
				System.out.print(j + " x " + i + " = " + (i * j) + "\t");

			}

		}
	}
}