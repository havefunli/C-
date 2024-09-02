#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void menu()
{
	printf("------------------------------------\n");
	printf("---------------1 play---------------\n");
	printf("---------------0 quit---------------\n");
	printf("------------------------------------\n");
}

void init_arr(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int k = 0;
		for (k = 0; k < COL; k++)
		{
			arr[i][k] = ' ';
		}
	}
}

void print_arr(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int k = 0;
		for (k = 0; k < col; k++)
		{
			printf(" %c ", arr[i][k]);
			if(k<col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void player_move(char arr[ROW][COL], int row, int col)
{
	printf("该你了，请输入下棋的坐标：");
	int x = 0, y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用，请重新输入：");
				break;
			}
		}
		else
			printf("坐标不合法，请重新输入：");
	}
}

void computer_move(char arr[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}

int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char WhoWin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];
		}
	}

	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[2][i] == arr[1][i] && arr[0][i] != ' ')
		{
			return arr[0][i];
		}
	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[0][0];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	if (IsFull(arr,ROW,COL) == 1)
		return 'B';
}

void play()
{
	char arr[ROW][COL];
	init_arr(arr, ROW, COL);
	print_arr(arr, ROW, COL);
	while (1)
	{
		player_move(arr, ROW, COL);
		print_arr(arr, ROW, COL);
		char ret=WhoWin(arr, ROW, COL);
		if (ret == '*')
		{
			printf("玩家赢了！\n");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑赢了！\n");
			break;
		}
		else if (ret == 'B')
		{
			printf("平局\n");
			break;
		}

		computer_move(arr, ROW, COL);
		print_arr(arr, ROW, COL);
		ret=WhoWin(arr, ROW, COL);
		if (ret == '*')
		{
			printf("玩家赢了！\n");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑赢了！\n");
			break;
		}
		else if (ret == 'B')
		{
			printf("平局\n");
			break;
		}
	}
}

void game()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			break;
		default:
			printf("选择错误！\n");
		}
	} while (input);
}

int main()
{
	//game();
	int arr[3][3] = { 1,2,3,4,5,6,7 };

	return 0;
}