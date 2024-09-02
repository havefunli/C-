#pragma once
void game()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);

		switch(input)
		{
		case 1:
			play();
			break;
		case 2:
			break;
		default:
			printf("选择错误！");
		}
	} while (input);
}