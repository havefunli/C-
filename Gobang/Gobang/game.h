#pragma once
void game()
{
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ��");
		scanf("%d", &input);

		switch(input)
		{
		case 1:
			play();
			break;
		case 2:
			break;
		default:
			printf("ѡ�����");
		}
	} while (input);
}