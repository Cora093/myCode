
public class test {
	public static void main(String[] args) {
		String str = "boolean类型的默认值是false";
		boolean[] bar = new boolean[2];
		if(bar[0]){
			str = "boolean类型的默认值是true";
		}
		System.out.println(str);
		// *boolean类型的默认值是false
	}
}