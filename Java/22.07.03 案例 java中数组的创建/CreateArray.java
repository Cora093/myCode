

public class CreateArray {
	public static void main(String[] args) {
		//����һ����СΪ5��double����
		//��һ�ַ�ʽ��ֱ��new
		double[] score1 = new double[5];

		//�ڶ��ַ�ʽ��������������new����ռ�
		double[] score2;
		score2 = new double[5];

		//�����ַ�ʽ����̬��ʼ��
		double[] score3 = {1, 2.3, 4, 88, 99};
		//����length������ȡ���鳤��
		System.out.println(score3.length);
	}
}