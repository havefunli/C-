#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int tem = 0;
	float floor = 0;
	printf("请输入温度: ");
	scanf("%d", &tem);

	if (tem >= 13 && tem < 26)
	{
		floor = 1.105 + (13 - tem) * 0.04 / 13;
		printf("实验爆炸下限为：%.3f",floor);
	}
	else if(tem >= 26 && tem < 37)
	{
		floor = 1.065 + (26 - tem) * 0.02 / 11;
		printf("实验爆炸下限为：%.3f", floor);
	}
	else if (tem >= 37 && tem < 45)
	{
		floor = 1.045 + (37 - tem) * 0.01 / 8;
		printf("实验爆炸下限为：%.3f", floor);
	}
	else
	{
		floor = 1.035 + (45 - tem) * 0.01 / 8;
		printf("实验爆炸下限为：%.3f", floor);
	}

	return 0;
}