import java.util.Scanner;//��ʾ��java.util�µ�Scanner�ർ��
public class Input {
	public static void main(String[] args) {
		//��ʾ�����û�������
		//����
		//1.����Scanner�����ڵİ�
		//2.����Scanner����
		Scanner sc = new Scanner(System.in);
		//3.�����û�������(ʹ����صķ���)
		System.out.println("����������");
		String name = sc.next();//���������String
		System.out.println("����������");
		int age = sc.nextInt();	//���������int	
		System.out.println("������нˮ");
		double salary = sc.nextDouble();//���������double

		System.out.println("��Ϣ���£�");
		System.out.println("���֣�" + name + "\t" + "���䣺" + age + "\t" 
			+ "нˮ��" + salary);
	}
}