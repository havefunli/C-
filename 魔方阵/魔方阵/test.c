#define  _CRT_SECURE_NO_WARNINGS 1
//2022_12_25 coded by liquan
//������ħ���󣨱߳�ΪN����ÿһ�л�ÿһ�л�ÿһб�����Ϊһ��������
//ԭ����1��N*N��������ħ�����С���ʼλ��1���ڵ�һ���м䣬�ٽ���һ����������һ����һ�У����ҷ���
//����������һ����������һ�У�����������һ������ڵ�һ��
//�����λ�ô��ڵ�����һ�������������һ��������һ��

#include <stdio.h>
#define ROW 105
#define COL 105

int IsLegal()
{
	int len = 0;
	while (1)
	{
		printf("��������ı߳���");
		scanf("%d", &len);
		//�߳���һ���������˴��жϣ�����Ƿ�����
		if (len == 1 || len % 2 == 0||len <= 0)
		{
			printf("�߳����Ϸ������������룺");
		}
		else
		{
			return len;
		}
	}
}

void Fill(int arr[ROW][COL], int len)
{
	//˫��ѭ���ṹ�������
	int i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void print(int arr[ROW][COL], int len)
{
	int i = 0, j = 0;
	//˫��ѭ����ӡ����
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			printf("%02d ", arr[i][j]);
		}
		printf("\n");
	}
}

void set_magic(int arr[ROW][COL], int len)
{
	int row = 0;
	int col = len / 2;
	int num = 2;
	int Max = len * len;
	//����Ѱ�ҳ�ʼλ�ã����ݹ���ɵ�1���ڵ�һ�ŵ��м�
	arr[row][col] = 1;
	// ��ͬ�߳���ħ�������1-Max=len*len�����֣���Max���˺�ѭ������
	while (num<=Max)
	{
		//�����������Ϸ�
		if (row - 1 < 0 || col + 1 > len - 1)
		{
			//��������һ��
			if (row - 1 < 0 && col + 1 <= len - 1)
			{
				//�ж����λ���Ƿ��������
				if (arr[len - 1][col + 1] == 0)
				{
					arr[len - 1][col + 1] = num;
					num++;
					row = len - 1;
					col = col + 1;
				}
				//�������֣��������һ��������һ��
				else
				{
					arr[row + 1][col] = num;
					num++;
					row = row + 1;
					col = col;
				}
			}
			//��������һ��
			else if (row - 1 >= 0 && col + 1 > len - 1)
			{
				//�ж����λ���Ƿ��������
				if (arr[row-1][0] == 0)
				{
					arr[row-1][0] = num;
					num++;
					row = row - 1;
					col = 0;
				}
				//�������֣��������һ��������һ��
				else
				{
					arr[row + 1][col] = num;
					num++;
					row = row + 1;
					col = col;
				}
			}
			//���Ȳ�������һ��Ҳ���������У���ֱ�ӷ�����һ������һ��
			else
			{
				arr[row + 1][col] = num;
				num++;
				row = row + 1;
				col = col;
			}
		}
		//������һ������һ�е����
		else
		{
			if (arr[row - 1][col + 1] == 0)
			{
				arr[row - 1][col + 1] = num;
				num++;
				row = row - 1;
				col = col + 1;
			}
			else
			{
				arr[row + 1][col] = num;
				num++;
				row = row + 1;
				col = col;
			}
		}
	}
}

void menu()
{
	printf("=====================\n");
	printf("======1 ħ����=======\n");
	printf("=======0 �˳�========\n");
	printf("=====================\n");
}

void game()
{
	//����һ���޴�Ķ�ά���飬�����㵱ħ����߳���������
	int arr[ROW][COL];
	//������Ŀ�涨�ж��û�����ı߳��Ƿ�����Ҫ��
	int len = IsLegal();
	//��ʼ��������ں����ж�
	Fill(arr, len);
	//����ħ����Ҫ���������
	set_magic(arr, len);
	system("cls");
	//��ӡħ����
	print(arr, len);
}

int main()
{
	int select = 0;
	//ʹ��do whileѭ���ɾ���ṹ
	do
	{
		menu();
		printf("�������ѡ��");
		scanf("%d", &select);
		//������������������������Ļ�Ϲ��治����
		system("cls");

		switch (select)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		}
	} while (select);//���û�ѡ��0ʱ����Ҫ�����ṹ��֧�֣��Զ�����ѭ��

	return 0;
}