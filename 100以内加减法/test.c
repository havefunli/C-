#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#define Max 1024

int cal(int a, int b,char arr[Max],int i)
{
	//�������һ��0-1������0����+��1����-
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
//������ʽ���ַ�������ʽ�洢
void print_question(int a, int b, int c,char arr1[Max],char arr2[Max],int i)
{
	printf("%d %c %d %c %d = ", a, arr1[i], b, arr2[i], c);
}

void IsRight(int standard, int result,int* p)
{
	if(standard==result)
	{
		printf("��ȷ���ٽ�������\n");
		printf("\n");
		(*p)++;
	}
	else
	{
		printf("����ȷ��������ϸ��\n");
		printf("\n");
	}
}

void print_eva(int all, int right)
{
	float rate = (float)right / all;

	printf("һ��%d���⣬��������%d����������%d������ȷ��Ϊ%.2f%%��", all, right, all - right, rate*100);

	if (rate == 1)
	{
		printf("Good��ϣ����ʱ�̱��֣�");
	}
	else if (rate >= 0.8 && rate < 1)
	{
		printf("ϣ���㲻�Ͼ����󾫣�");
	}
	else if (rate >= 0.6 && rate < 0.8)
	{
		printf("ǰ����·���кܳ���Ҫ���ϼ�֣�");
	}
	else
		printf("���ϵ�ѯ���Լ����Լ������������");
}

int main()
{
	//numΪ�����õ���Ŀ������iΪ������ļ�������countΪ��ȷ��ļ�����
	int num = 0,i = 0,count=0;
	//�ֱ����������ַ����飬�ֱ𱣴��һ���͵ڶ���������ţ����㵽����ӡ
	char arr1[Max];
	char arr2[Max];
	while(1)
	{
		printf("������������Ҫ��������");
		scanf("%d", &num);
		if (num >= 5)
			break;
		else
			printf("�������ô�����������أ�����һ��ɣ�\n");
	}
	printf("\n");

	srand((unsigned int)time(NULL));
	while (i < num)
	{
		//�ֱ������������0-99����������һ�������н��м�����Ľ������������ص��ж��Ƿ���������
		int a = rand() % 100;
		int b = rand() % 100;
		int c = rand() % 100;
		int d = 0;
		//����һ�μ��㣬�����������͸ôμ�����ʹ�õķ��Ŵ���
		d = cal(a, b,arr1,i);
		//printf("%d", d);
		//�����жϣ��ôμ������Ƿ�������Ŀ���������������������� 
		if (d > 0 && d < 100)
		{
			d = cal(d, c,arr2,i);
			//���ж����жϣ��ôμ������Ƿ�������Ŀ���������������������� 
			if (d > 0 && d < 100)
			{
				//��ӡ����Ŀ
				print_question(a, b, c,arr1,arr2,i);
				//�����Լ��ĵĴ𰸣������׼�𰸱Ƚ�
				int result = 0;
				scanf("%d", &result);
				IsRight(d,result,&count);
				i++;//ÿ����һ����Ŀ������
			}
			else
				continue;
		}
		else
			continue;
	}
	//������ȷ�ʸ�������
	print_eva(num, count);

	return 0;
}