//�����������ͺ��ַ�����ת��

public class StringToBasic {

	public static void main(String[] args) {
		
		//������������->String
		//�üӺ�����

		int n1 = 100;
		float f1 = 3.14f;
		double d1 = 4.5;
		boolean b1 = true;

		String s1 = n1 + "";	
		String s2 = f1 + "";	
		String s3 = d1 + "";	
		String s4 = b1 + "";	

		System.out.println(s1 + " " + s2 + " " + s3 + " " + s4);

		//string->������������
		//ʹ�û����������Ͷ�Ӧ�İ�װ���е�parse��������stringת���ɻ�����������

		int n2 = Integer.parseInt(s1);
		double d2 = Double.parseDouble(s1);
		//�Դ�����

		System.out.println(n2);//100
		System.out.println(d2);//100.0

		//��ô���ַ���ת���ַ�char->������ָ���ַ����ĵ�һ���ַ��õ�
		System.out.println(s4.charAt(0));//t
		


	}
}