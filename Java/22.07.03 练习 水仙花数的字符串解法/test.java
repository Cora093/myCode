public class test {
	public static void main(String[] args) {
		int n = 153;
		String s1 = n + "";
		int n1 = s1.charAt(0) - '0';
		int n2 = s1.charAt(1) - '0';
		int n3 = s1.charAt(2) - '0';
		System.out.println("百位 十位 个位 分别为：" + n1 + " " + n2 + " " + n3);
		
	}
}