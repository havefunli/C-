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
	printf("========1 ������=======\n");
	printf("========2 ���Բ�=======\n");
	printf("========0 ����=========\n");
	printf("=======================\n");
}

void player()
{
	int count = 0;
	int guess = 0;
	int num = rand() % 100 + 1;//�������һ������
	time_t start, end;//��ʱ��ʼ
	printf("��Ϸ��ʼ��\n");
	start = time(NULL);
	while (1)
	{
		printf("������²�����֣�");
		scanf("%d", &guess);
		count++;
		//���Ը�����ʾ��֪�������˳�
		if (guess > num)
		{
			printf("�´��ˣ�\n");
		}
		else if (guess < num)
		{
			printf("��С�ˣ�\n");
		}
		else
		{
			printf("bingo\n");
			break;
		}
	}
	end = time(NULL);//��ʱ����
	printf("������%.2fs���У�\n", difftime(end, start));
}
//���ṩ����ʾ�Ľ�������
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
	//����Ѱ�����ֵķ�����
	//��1���������һ����Χ�ڵ����֣�ȱ��������ԡ�����������ɵ������ܷ�µ�ֻ�ܿ�����
	//���п����ڷǳ�����ʱ���Ҳ�����ҵ�
	//��2�����ö��ַ����ٶ�λ����λ�ã�ȱ�㣺���û������������ʾ����ַ��޷���λ����ȷ���ֵ�λ��
	//���ڲ�����ȷ������£��ɿ��ٶ�λ�����ֵ�λ��
	int left = 0;
	int right = 101;
	int mid = (left + right) / 2;//���ַ���һ���������Ҷ˵�λ��
	int tip = 99;
	int guess = rand() % 100 + 1;//�������һ�����õ��Բ�
	time_t start, end;//��ʱ
	printf("��Ϸ��ʼ��\n");
	start = time(NULL);
	printf("���ֵ�������%d�����computer׼ȷ����ʾ�ɣ�\n", guess);
	printf("���Բ£�%d\n", mid);
	while(tip!=3&&tip!=0)
	{
		int judge = mid;
		Give_tip();
		scanf("%d", &tip);
		//�����ֲ´��ˣ�����˵�������£�������е�λ��
		if (tip == 1)
		{
			right = mid;
			mid = (left + right) / 2;
			printf("���Բ£�%d\n", mid);
		}
		//�����ֲ�С�ˣ����Ҷ˵�������£�������е�λ��
		else if (tip == 2)
		{
			left = mid;
			mid = (left + right) / 2;
			printf("���Բ£�%d\n", mid);
		}
	}
	end = time(NULL);//��ʱ����
	if(tip==3)
		printf("computer����%.2fs���У�\n", difftime(end, start));
	else
		printf("computer��Ϊ�ѣ���Ϊ��û�ҵ��Ǹ�����QAQ\n");
}

void game()
{
	int n = 0;
	do
	{
		menu2();
		printf("���������ѡ��");
		scanf("%d", &n);
		//����������ʹʹ���߱��ڹۿ�Ч��
		system("cls");
		switch (n)
		{
		case 1:
			//�˲�����
			player();
			break;
		case 2:
			//���Բ����֣��˸���ʾ
			computer();
			break;
			//�˳���Ϸ
		case 0:
			break;
		default:
			printf("���벻�Ϸ�!\n");
			break;
		}	
	} while (n);
}

void mainmenu()
{
	int select = 0;
	do
	{
		//��ӡ���˵����ڽ���
		menu1();
		printf("���������ѡ��");
		scanf("%d", &select);
		system("cls");
		//switch�ṹ����ѡ��
		switch (select)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("���벻�Ϸ�!\n");
			break;
		}
	} while (select);
}

int main()
{
	//����������ֵĺ���
	srand((unsigned int)time(NULL));
	mainmenu();

	return 0;
}