#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���Ѽ���
//�����Ϊ3����𲽷�10Ԫ��
//������̺�10�����ڣ�ÿ����2Ԫ��
//����10�������ϵĲ��ּ���50% �Ļؿղ����ѣ���ÿ����3Ԫ��
//Ӫ�˹����У���·�輰�˿�Ҫ����ʱͣ���ģ���ÿ5����2Ԫ���գ�����5�������շѣ���
//������ʻ��̣������ȷ��С�����1λ����ȴ�ʱ�䣨��������λΪ���ӣ�������Կո�ָ���
//����˿�Ӧ֧���ĳ��ѣ���λΪԪ��������������룬������Ԫ��
int main()
{
	int time = 0, a = 0;
	float km = 0, charge = 0, charge1 = 0, charge2 = 0;
	scanf("%f %d", &km, &time);
	if (km <= 3)
		a = 1;						//���������
	if (km > 3 && km <= 10)
		a = 2;						//�������10������
	if (km > 10)
		a = 3;						//����10��������

	switch (a)
	{
	case 1:charge1 = 10; break;
	case 2:charge1 = 10 + (km - 3) * 2; break;
	case 3:charge1 = 24 + (km - 10) * 3; break;
	default:printf("error");
		break;
	}
	charge2 = time / 5 * 2;
	charge = charge1 + charge2;
	if (charge - 0.5 >= charge / 1) charge = charge / 1 + 1;
	else charge = charge / 1;
	printf("%.0f", charge);
}
