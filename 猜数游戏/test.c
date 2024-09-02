#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu1()
{
	printf("=======================\n");
	printf("=========1 play========\n");
	printf("=========0 exit========\n");
	printf("=======================\n");
}

void menu2()
{
	printf("=======================\n");
	printf("========1 我来猜=======\n");
	printf("========2 电脑猜=======\n");
	printf("========0 返回=========\n");
	printf("=======================\n");
}

void player()
{
	int count = 0;
	int guess = 0;
	int num = rand() % 100 + 1;//随机生成一个数字
	time_t start, end;//计时开始
	printf("游戏开始！\n");
	start = time(NULL);
	while (1)
	{
		printf("请输入猜测的数字：");
		scanf("%d", &guess);
		count++;
		//电脑给出提示，知道猜中退出
		if (guess > num)
		{
			printf("猜大了！\n");
		}
		else if (guess < num)
		{
			printf("猜小了！\n");
		}
		else
		{
			printf("bingo\n");
			break;
		}
	}
	end = time(NULL);//计时结束
	printf("你用了%.2fs猜中！\n", difftime(end, start));
}
//人提供的提示的交互界面
void Give_tip()
{
	printf("------------------\n");
	printf("------1 big-------\n");
	printf("------2 small-----\n");
	printf("------3 bingo-----\n");
	printf("------0 exit------\n");
	printf("------------------\n");

}

void computer()
{
	//电脑寻找数字的方法：
	//法1：随机生成一个范围内的数字，缺点过于明显。电脑随机生成的数字能否猜到只能靠运气
	//极有可能在非常长的时间后也不能找到
	//法2：利用二分法快速定位数的位置，缺点：若用户给出错误的提示后二分法无法定位到正确数字的位置
	//但在操作正确的情况下，可快速定位到数字的位置
	int left = 0;
	int right = 101;
	int mid = (left + right) / 2;//二分法第一步定义左右端点位置
	int tip = 99;
	int guess = rand() % 100 + 1;//随机生成一个数让电脑猜
	time_t start, end;//计时
	printf("游戏开始！\n");
	start = time(NULL);
	printf("本轮的数字是%d，请给computer准确的提示吧！\n", guess);
	printf("电脑猜：%d\n", mid);
	while(tip!=3&&tip!=0)
	{
		int judge = mid;
		Give_tip();
		scanf("%d", &tip);
		//若数字猜大了，则将左端点向右收拢，来到中点位置
		if (tip == 1)
		{
			right = mid;
			mid = (left + right) / 2;
			printf("电脑猜：%d\n", mid);
		}
		//若数字猜小了，则将右端点向左收拢，来到中点位置
		else if (tip == 2)
		{
			left = mid;
			mid = (left + right) / 2;
			printf("电脑猜：%d\n", mid);
		}
	}
	end = time(NULL);//计时结束
	if(tip==3)
		printf("computer用了%.2fs猜中！\n", difftime(end, start));
	else
		printf("computer很为难，因为他没找到那个数！QAQ\n");
}

void game()
{
	int n = 0;
	do
	{
		menu2();
		printf("请输入你的选择：");
		scanf("%d", &n);
		//清屏操作，使使用者便于观看效果
		system("cls");
		switch (n)
		{
		case 1:
			//人猜数字
			player();
			break;
		case 2:
			//电脑猜数字，人给提示
			computer();
			break;
			//退出游戏
		case 0:
			break;
		default:
			printf("输入不合法!\n");
			break;
		}	
	} while (n);
}

void mainmenu()
{
	int select = 0;
	do
	{
		//打印主菜单便于交互
		menu1();
		printf("请输入你的选择：");
		scanf("%d", &select);
		system("cls");
		//switch结构便于选择
		switch (select)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入不合法!\n");
			break;
		}
	} while (select);
}

int main()
{
	//随机生成数字的函数
	srand((unsigned int)time(NULL));
	mainmenu();

	return 0;
}