#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//车费计算
//起步里程为3公里，起步费10元；
//超起步里程后10公里内，每公里2元；
//超过10公里以上的部分加收50% 的回空补贴费，即每公里3元；
//营运过程中，因路阻及乘客要求临时停车的，按每5分钟2元计收（不足5分钟则不收费）。
//输入行驶里程（公里，精确到小数点后1位）与等待时间（整数，单位为分钟），其间以空格分隔。
//输出乘客应支付的车费（单位为元），结果四舍五入，保留到元。
int main()
{
	int time = 0, a = 0;
	float km = 0, charge = 0, charge1 = 0, charge2 = 0;
	scanf("%f %d", &km, &time);
	if (km <= 3)
		a = 1;						//起步里程以内
	if (km > 3 && km <= 10)
		a = 2;						//超起步里程10公里内
	if (km > 10)
		a = 3;						//超过10公里以上

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
