#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#define Max 1024

int cal(int a, int b,char arr[Max],int i)
{
	//随机产生一个0-1的数，0进行+，1进行-
	int choice = rand() % 2;

	switch (choice)
	{
	case 0:
		arr[i] = '+';
		return a + b;
	case 1:
		arr[i] = '-';
		return (a - b);
	}
}
//将计算式以字符串的形式存储
void print_question(int a, int b, int c,char arr1[Max],char arr2[Max],int i)
{
	printf("%d %c %d %c %d = ", a, arr1[i], b, arr2[i], c);
}

void IsRight(int standard, int result,int* p)
{
	if(standard==result)
	{
		printf("正确！再接再厉！\n");
		printf("\n");
		(*p)++;
	}
	else
	{
		printf("不正确！审题仔细！\n");
		printf("\n");
	}
}

void print_eva(int all, int right)
{
	float rate = (float)right / all;

	printf("一共%d道题，你做对了%d道，做错了%d道。正确率为%.2f%%。", all, right, all - right, rate*100);

	if (rate == 1)
	{
		printf("Good！希望你时刻保持！");
	}
	else if (rate >= 0.8 && rate < 1)
	{
		printf("希望你不断精益求精！");
	}
	else if (rate >= 0.6 && rate < 0.8)
	{
		printf("前方的路还有很长，要不断坚持！");
	}
	else
		printf("不断地询问自己，自己真的认真了吗？");
}

int main()
{
	//num为所设置的题目数量，i为所做题的计数器，count为正确题的计数器
	int num = 0,i = 0,count=0;
	//分别设置两个字符数组，分别保存第一个和第二个计算符号，方便到最后打印
	char arr1[Max];
	char arr2[Max];
	while(1)
	{
		printf("请输入你所需要的题数：");
		scanf("%d", &num);
		if (num >= 5)
			break;
		else
			printf("这点题怎么够你塞牙缝呢？多来一点吧！\n");
	}
	printf("\n");

	srand((unsigned int)time(NULL));
	while (i < num)
	{
		//分别随机生成三个0-99的数，并用一个数来承接中间和最后的结果，并进行相关的判断是否满足条件
		int a = rand() % 100;
		int b = rand() % 100;
		int c = rand() % 100;
		int d = 0;
		//进行一次计算，并将计算结果和该次计算所使用的符号储存
		d = cal(a, b,arr1,i);
		//printf("%d", d);
		//进行判断，该次计算结果是否满足题目条件，若不满足重新生成 
		if (d > 0 && d < 100)
		{
			d = cal(d, c,arr2,i);
			//进行二次判断，该次计算结果是否满足题目条件，若不满足重新生成 
			if (d > 0 && d < 100)
			{
				//打印出题目
				print_question(a, b, c,arr1,arr2,i);
				//输入自己的的答案，并与标准答案比较
				int result = 0;
				scanf("%d", &result);
				IsRight(d,result,&count);
				i++;//每进行一道题目就增加
			}
			else
				continue;
		}
		else
			continue;
	}
	//根据正确率给出评语
	print_eva(num, count);

	return 0;
}