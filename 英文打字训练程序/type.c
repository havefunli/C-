#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define Max 1024
#define num 100

void mainmenu()
{
	printf("=====================\n");
	printf("=======1 打字训练====\n");
	printf("=======0 退出========\n");
	printf("=====================\n");
}

void menu()
{
	printf("================\n");
	printf("=====1 初阶=====\n");
	printf("=====2 进阶=====\n");
	printf("=====0 退出=====\n");
	printf("================\n");
}
//倒计时函数，倒计时后开始训练
void countdown()
{
	int time=3;
	while (time>= 0)
	{
		printf("%d", time);
		Sleep(1000);
		system("cls");
		time--;
	}
}
//该函数用于生成100个字母，并存于文件和数组中
void creat_essay(char essay[Max])
{
	int count = 0;
	while (count < num)
	{
		//每打印20个字母后换行，避免太长
		if (count>0 && count % 20 == 0)
		{
			essay[count] = '\n';
			count++;
		}
		//生成a-z的字母
		essay[count] = 'a' + rand() % 26;
		count++;
	}
	//字符串最后添上斜杠0避免打印时越界
	essay[count] = '\0';
	//读入文件的操作
	FILE* fp;
	fp = fopen("model essay.txt", "w");
	fprintf(fp, "%s", essay);
	fclose(fp);//读入后别忘了关闭文件
}

void letter(char essay[Max],char type[Max])
{
	//清屏操作
	system("cls");
	int count = 0;
	creat_essay(essay);
	countdown();//倒计时
	time_t start, end;
	printf("%s\n", essay);
	printf("训练开始！\n");
	start = time(NULL);//开始计时
	rewind(stdin);
	//用户写入字母，并判断正误且统计正确的个数
	//此处使用getchar，因为getchar几乎可以输入所有字符包括换行符
	for (int i = 0; i < num; i++)
	{
		type[i] = getchar();
		if (type[i] == essay[i])
			count++;
	}
	end = time(NULL);//结束计时
	type[num] = '\0';//末尾添上斜杠0
	//打开文件，将用户输入的所有字符存入文件中
	FILE* fp;
	fp = fopen("typewriting.txt", "w");
	fprintf(fp, "%s", type);
	fclose(fp);
	//在屏幕上给出用时和正确率
	printf("训练结束!\n你所用时%.2fs.正确率为%d%%\n",difftime(end, start),count);
}
//这里存在三篇英语短文，当用户选择进阶模式时，会随机选择三篇中的一篇进行训练
void model(char type[Max])
{
	//清屏操作
	system("cls");
	char arr[Max];
	FILE* fp;
	//随机生成一个1-3的数字来选择文章
	int select = rand() % 3 + 1;
	select = 1;
	if (select == 1)
	{
		//打开第一篇的文件写入数组中
		fp = fopen("model1.txt", "r");
		fgets(arr, 461, fp);
		fclose(fp);
		//计算该篇文章的字符数量，便于统计正确率
		int len = strlen(arr);
		int count = 0;
		//倒计时
		countdown();
		time_t start, end;
		printf("训练开始！\n");
		printf("%s\n", arr);
		//开始计时
		start = time(NULL);
		rewind(stdin);
		for (int i = 0; i < len; i++)
		{
			type[i] = getchar();
			if (type[i] == arr[i])
				count++;
		}
		//结束计时
		end = time(NULL);
		type[len] = '\0';
		//给出所用时间和正确率
		printf("训练结束!\n你所用时%.2fs.正确率为%.2f%%\n", difftime(end, start), (float)count*100 / len);
	}
	else if (select == 2)
	{
		fp = fopen("model2.txt", "r");
		fgets(arr, 284, fp);
		fclose(fp);
		int len = strlen(arr);
		int count = 0;
		countdown();
		time_t start, end;
		printf("训练开始！\n");
		printf("%s\n", arr);
		start = time(NULL);
		rewind(stdin);
		for (int i = 0; i < len; i++)
		{
			type[i] = getchar();
			if (type[i] == arr[i])
				count++;
		}
		end = time(NULL);
		type[len] = '\0';
		printf("训练结束!\n你所用时%.2fs.正确率为%.2f%%\n", difftime(end, start), (float)count * 100 / len);
	}
	else
	{
		fp = fopen("model3.txt", "r");
		fgets(arr, 345, fp);
		fclose(fp);
		int len = strlen(arr);
		int count = 0;
		countdown();
		time_t start, end;
		printf("训练开始！\n");
		printf("%s\n", arr);
		start = time(NULL);
		rewind(stdin);
		for (int i = 0; i < len; i++)
		{
			type[i] = getchar();
			if (type[i] == arr[i])
				count++;
		}
		end = time(NULL);
		type[len] = '\0';
		printf("训练结束!\n你所用时%.2fs.正确率为%.2f%%\n", difftime(end, start), (float)count * 100 / len);
	}
}

void go_type()
{
	//清除屏幕，打印出内容
	system("cls");
	//使用两个字符数组，一个装打印内容，一个装用户打印结果
	char essay[Max];
	char type[Max];
	int select = 0;
	do
	{
		menu();
		printf("请输入你的选择：");
		rewind(stdin);
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//初阶打印，打印随机生成的一百个字母
			letter(essay,type);
			break;
		case 2:
			//进阶打印，打印一篇英语短文，内容不只有字母
			model(type);
			break;
		case 0:
			break;
		default:
			printf("输入不合法！\n");
			break;
		}
	} while (select);
}

int main()
{
	//随机生成数字
	srand((unsigned int)time(NULL));
	int select = 0;
	//使用do while循环便于选择
	do
	{
		mainmenu();
		printf("请输入你的选择：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//打字模块
			go_type();
			break;
			//退出
		case 0:
			break;
		default:
			printf("输入不合法！\n");
			break;
		}
	} while (select);
}