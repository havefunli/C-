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
	printf("=======1 ����ѵ��====\n");
	printf("=======0 �˳�========\n");
	printf("=====================\n");
}

void menu()
{
	printf("================\n");
	printf("=====1 ����=====\n");
	printf("=====2 ����=====\n");
	printf("=====0 �˳�=====\n");
	printf("================\n");
}
//����ʱ����������ʱ��ʼѵ��
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
//�ú�����������100����ĸ���������ļ���������
void creat_essay(char essay[Max])
{
	int count = 0;
	while (count < num)
	{
		//ÿ��ӡ20����ĸ���У�����̫��
		if (count>0 && count % 20 == 0)
		{
			essay[count] = '\n';
			count++;
		}
		//����a-z����ĸ
		essay[count] = 'a' + rand() % 26;
		count++;
	}
	//�ַ����������б��0�����ӡʱԽ��
	essay[count] = '\0';
	//�����ļ��Ĳ���
	FILE* fp;
	fp = fopen("model essay.txt", "w");
	fprintf(fp, "%s", essay);
	fclose(fp);//���������˹ر��ļ�
}

void letter(char essay[Max],char type[Max])
{
	//��������
	system("cls");
	int count = 0;
	creat_essay(essay);
	countdown();//����ʱ
	time_t start, end;
	printf("%s\n", essay);
	printf("ѵ����ʼ��\n");
	start = time(NULL);//��ʼ��ʱ
	rewind(stdin);
	//�û�д����ĸ�����ж�������ͳ����ȷ�ĸ���
	//�˴�ʹ��getchar����Ϊgetchar�����������������ַ��������з�
	for (int i = 0; i < num; i++)
	{
		type[i] = getchar();
		if (type[i] == essay[i])
			count++;
	}
	end = time(NULL);//������ʱ
	type[num] = '\0';//ĩβ����б��0
	//���ļ������û�����������ַ������ļ���
	FILE* fp;
	fp = fopen("typewriting.txt", "w");
	fprintf(fp, "%s", type);
	fclose(fp);
	//����Ļ�ϸ�����ʱ����ȷ��
	printf("ѵ������!\n������ʱ%.2fs.��ȷ��Ϊ%d%%\n",difftime(end, start),count);
}
//���������ƪӢ����ģ����û�ѡ�����ģʽʱ�������ѡ����ƪ�е�һƪ����ѵ��
void model(char type[Max])
{
	//��������
	system("cls");
	char arr[Max];
	FILE* fp;
	//�������һ��1-3��������ѡ������
	int select = rand() % 3 + 1;
	select = 1;
	if (select == 1)
	{
		//�򿪵�һƪ���ļ�д��������
		fp = fopen("model1.txt", "r");
		fgets(arr, 461, fp);
		fclose(fp);
		//�����ƪ���µ��ַ�����������ͳ����ȷ��
		int len = strlen(arr);
		int count = 0;
		//����ʱ
		countdown();
		time_t start, end;
		printf("ѵ����ʼ��\n");
		printf("%s\n", arr);
		//��ʼ��ʱ
		start = time(NULL);
		rewind(stdin);
		for (int i = 0; i < len; i++)
		{
			type[i] = getchar();
			if (type[i] == arr[i])
				count++;
		}
		//������ʱ
		end = time(NULL);
		type[len] = '\0';
		//��������ʱ�����ȷ��
		printf("ѵ������!\n������ʱ%.2fs.��ȷ��Ϊ%.2f%%\n", difftime(end, start), (float)count*100 / len);
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
		printf("ѵ����ʼ��\n");
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
		printf("ѵ������!\n������ʱ%.2fs.��ȷ��Ϊ%.2f%%\n", difftime(end, start), (float)count * 100 / len);
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
		printf("ѵ����ʼ��\n");
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
		printf("ѵ������!\n������ʱ%.2fs.��ȷ��Ϊ%.2f%%\n", difftime(end, start), (float)count * 100 / len);
	}
}

void go_type()
{
	//�����Ļ����ӡ������
	system("cls");
	//ʹ�������ַ����飬һ��װ��ӡ���ݣ�һ��װ�û���ӡ���
	char essay[Max];
	char type[Max];
	int select = 0;
	do
	{
		menu();
		printf("���������ѡ��");
		rewind(stdin);
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//���״�ӡ����ӡ������ɵ�һ�ٸ���ĸ
			letter(essay,type);
			break;
		case 2:
			//���״�ӡ����ӡһƪӢ����ģ����ݲ�ֻ����ĸ
			model(type);
			break;
		case 0:
			break;
		default:
			printf("���벻�Ϸ���\n");
			break;
		}
	} while (select);
}

int main()
{
	//�����������
	srand((unsigned int)time(NULL));
	int select = 0;
	//ʹ��do whileѭ������ѡ��
	do
	{
		mainmenu();
		printf("���������ѡ��");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//����ģ��
			go_type();
			break;
			//�˳�
		case 0:
			break;
		default:
			printf("���벻�Ϸ���\n");
			break;
		}
	} while (select);
}