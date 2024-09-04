#define  _CRT_SECURE_NO_WARNINGS 1
//2022_12_25 coded by liquan
//奇数阶魔方阵（边长为N）：每一行或每一列或每一斜行相加为一个常数。
//原理：将1到N*N个数放入魔方阵中。初始位置1放在第一行中间，再将下一个数放在上一行下一列（上右方）
//若不存在上一行则放在最后一行，若不存在下一列则放在第一列
//若填充位置存在但存在一个数字则放在上一个数字下一列

#include <stdio.h>
#define ROW 105
#define COL 105

int IsLegal()
{
	int len = 0;
	while (1)
	{
		printf("请输入你的边长：");
		scanf("%d", &len);
		//边长是一个奇数，此处判断，避免非法输入
		if (len == 1 || len % 2 == 0||len <= 0)
		{
			printf("边长不合法，请重新输入：");
		}
		else
		{
			return len;
		}
	}
}

void Fill(int arr[ROW][COL], int len)
{
	//双重循环结构填充数组
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
	//双重循环打印数组
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
	//首先寻找初始位置，根据规则可得1填在第一排的中间
	arr[row][col] = 1;
	// 不同边长的魔方阵存在1-Max=len*len个数字，当Max填了后循环结束
	while (num<=Max)
	{
		//若不存在右上方
		if (row - 1 < 0 || col + 1 > len - 1)
		{
			//不存在上一行
			if (row - 1 < 0 && col + 1 <= len - 1)
			{
				//判断填充位置是否存在数字
				if (arr[len - 1][col + 1] == 0)
				{
					arr[len - 1][col + 1] = num;
					num++;
					row = len - 1;
					col = col + 1;
				}
				//存在数字，则放在上一个数字下一列
				else
				{
					arr[row + 1][col] = num;
					num++;
					row = row + 1;
					col = col;
				}
			}
			//不存在下一列
			else if (row - 1 >= 0 && col + 1 > len - 1)
			{
				//判断填充位置是否存在数字
				if (arr[row-1][0] == 0)
				{
					arr[row-1][0] = num;
					num++;
					row = row - 1;
					col = 0;
				}
				//存在数字，则放在上一个数字下一列
				else
				{
					arr[row + 1][col] = num;
					num++;
					row = row + 1;
					col = col;
				}
			}
			//若既不存在上一行也不存在下列，则直接放在上一个数下一列
			else
			{
				arr[row + 1][col] = num;
				num++;
				row = row + 1;
				col = col;
			}
		}
		//存在上一行且下一列的情况
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
	printf("======1 魔方阵=======\n");
	printf("=======0 退出========\n");
	printf("=====================\n");
}

void game()
{
	//申请一个巨大的二维数组，可满足当魔方阵边长所有需求
	int arr[ROW][COL];
	//根据题目规定判断用户输入的边长是否满足要求
	int len = IsLegal();
	//初始化数组便于后续判断
	Fill(arr, len);
	//根据魔方阵要求填充数组
	set_magic(arr, len);
	system("cls");
	//打印魔方阵
	print(arr, len);
}

int main()
{
	int select = 0;
	//使用do while循环可精简结构
	do
	{
		menu();
		printf("输入你的选择：");
		scanf("%d", &select);
		//清屏操作，避免多组输出在屏幕上共存不美观
		system("cls");

		switch (select)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		}
	} while (select);//当用户选择0时不需要其他结构的支持，自动结束循环

	return 0;
}