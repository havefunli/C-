#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "struct.h"
//����Ϊѧ�������������ڴ�����Ӧ���ȵ�����
stu*  Creatlink(int lenth)
{
	//����ͷ�巨��������
	stu* head, *p;
	//����ͷ
	head = (stu* )malloc(sizeof(stu));
	head->next = NULL;
	int i = 0;
	//������Ӧ��������
	while (i < lenth)
	{
		p = (stu* )malloc(sizeof(stu));
		p->next = head->next;
		head->next = p;
		i++;
	}
	//������ͷ���أ�������������ʹ��
	return head;
}
//���ļ��ж�ȡѧ������Ϣ��д��������
void Fileread(stu* head ,int lenth)
{
	int i = 0;
	stu* p;
	p = head->next;
	//�ļ�ָ�����Ӧ�ļ�
	FILE* fp;
	fp = fopen("student information.txt", "r");
	
	rewind(stdin);
	//������������д����Ϣ
	while (i < lenth)
	{
		fscanf(fp, "%s", &(p->class));
		fscanf(fp, "%s", &(p->num));
		fscanf(fp, "%s", &(p->name));
		fscanf(fp, "%s", &(p->sex));
		fscanf(fp, "%s", &(p->id));
		fscanf(fp, "%s", &(p->password));
		fscanf(fp, "%d", &(p->math));
		fscanf(fp, "%d", &(p->english));
		fscanf(fp, "%d", &(p->pro));
		//����������ָ����һ������
		p = p->next;
		i++;
	}
	fclose(fp);
}

void menu()
{
	printf("=========================\n");
	printf("=========1 ����Ա========\n");
	printf("=========2 ѧ��==========\n");
	printf("=========0 �˳�==========\n");
	printf("=========================\n");
}

void manager_menu()
{
	printf("===============================\n");
	printf("=========1 ���ѧ����Ϣ========\n");
	printf("=========2 ��ѯѧ����Ϣ========\n");
	printf("=========3 ɾ��ѧ����Ϣ========\n");
	printf("=========4 �޸�ѧ����Ϣ========\n");
	printf("=========5 ���ѧ���ɼ����====\n");
	printf("=========6 ȫ��ѧ����Ϣ========\n");
	printf("=========7 �޸Ĺ���Ա��Ϣ======\n");
	printf("=========0 �˳�================\n");
	printf("===============================\n");
}

void select_menu()
{
	printf("====================\n");
	printf("=======1 ѧ��=======\n");
	printf("=======2 ����=======\n");
	printf("=======0 �˳�=======\n");
	printf("====================\n");
}

void revise_menu()
{
	printf("=======================\n");
	printf("=======1 ����==========\n");
	printf("=======2 ��ѧ==========\n");
	printf("=======3 Ӣ��==========\n");
	printf("=======4 �������======\n");
	printf("=======0 �˳�==========\n");
	printf("=======================\n");
}

void add_student(stu* head)
{
	stu* p;
	stu* que;
	int i = 0;
	//����һ������ռ������ѧ����Ϣ
	p = (stu*)malloc(sizeof(stu));
	p->next = head->next;
	head->next = p;
	//Ϊ����ѧ���ظ����ò��������أ����ظ�����������ѧ��
	while (i == 0)
	{
		que = p->next;
		printf("������ѧ�ţ�");
		rewind(stdin);
		scanf("%s", &(p->num));
		//��������Ѱ���Ƿ������ͬѧ��
		while (que != NULL)
		{
			if (strcmp(que->num, p->num )==0)
				break;
			que = que->next;
		}
		if (que != NULL)
		{
			printf("���˺��Ѵ��ڣ�\n");
			i = 0;
		}
		else
			i = 1;
	}
	//������ǰ��ռ��̻�����������س������������
	rewind(stdin);
	printf("������༶��");
	scanf("%s", &(p->class));
	rewind(stdin);
	printf("������������");
	scanf( "%s", &(p->name));
	rewind(stdin);
	printf("�������Ա�");
	scanf("%s", &(p->sex));
	rewind(stdin);
	printf("���������֤��");
	scanf("%s", &(p->id));
	rewind(stdin);
	printf("�봴�����룺");
	scanf("%s", &(p->password));
	rewind(stdin);
	printf("��������ѧ�ɼ���");
	scanf("%d", &(p->math));
	rewind(stdin);
	printf("������Ӣ��ɼ���");
	scanf("%d", &(p->english));
	rewind(stdin);
	printf("��������Ƴɼ���");
	scanf("%d", &(p->pro));
	//���ļ�����ѧ����Ϣ�б䶯ʱ����д��
	FILE* fp;
	fp = fopen("student information.txt", "a");
	rewind(stdin);
	fprintf(fp, "\n%s ", &(p->class));
	fprintf(fp, "%s ", &(p->num));
	fprintf(fp, "%s ", &(p->name));
	fprintf(fp, "%s ", &(p->sex));
	fprintf(fp, "%s ", &(p->id));
	fprintf(fp, "%s ", &(p->password));
	fprintf(fp, "%d ", p->math);
	fprintf(fp, "%d ", p->english);
	fprintf(fp, "%d\n", p->pro);
	fclose(fp);
	printf("��ӳɹ���\n");
	Sleep(1000);
	system("cls");
}
//�˴β����ж����������ṹָ�룬��һǰһ��
//����ɾ��ѧ����ϢҲ�����ͷŸ�����ռ�ʱ����ʧ�������Ժ��ȫ�������ַ
void delete_student(stu* head,int* num)
{
	char arr[15];
	stu* p,*det;
	p = head;
	det = p->next;
	printf("��������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%s", arr);
	system("cls");
	//��������Ѱ���Ƿ����Ҫɾ����ѧ���ţ�������ɾ���������ڸ�������
	while (det != NULL)
	{
		if (strcmp(arr, det->num) == 0)
			break;
		else
		{
			//����ʽ��ǰ��������
			p = det;
			det = p->next;
		}
	}
	if (det == NULL)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		p->next = det->next;
		free(det);
		printf("ɾ���ɹ���\n");
		//���ļ�����ѧ����Ϣ�б䶯ʱ����д��
		FILE* fp;
		fp = fopen("student information.txt", "w");
		p = head->next;
		rewind(stdin);
		while (p != NULL)
		{
			fprintf(fp, "%s ", p->class);
			fprintf(fp, "%s ", p->num);
			fprintf(fp, "%s ", p->name);
			fprintf(fp, "%s ", p->sex);
			fprintf(fp, "%s ", p->id);
			fprintf(fp, "%s ", p->password);
			fprintf(fp, "%d ", p->math);
			fprintf(fp, "%d ", p->english);
			fprintf(fp, "%d\n", p->pro);
			p = p->next;
		}
		fclose(fp);
		//ѧ��������һ
		(*num)--;
	}
}

void revise_password(stu* head,stu* p)
{
	printf("�������µ����룺");
	rewind(stdin);
	scanf("%s", &(p->password));
	system("cls");

	//���ļ�����ѧ����Ϣ�б䶯ʱ����д��
	FILE* fp;
	fp = fopen("student information.txt", "w");
	p = head->next;
	while (p != NULL)
	{
		fprintf(fp, "%s ", p->class);
		fprintf(fp, "%s ", p->num);
		fprintf(fp, "%s ", p->name);
		fprintf(fp, "%s ", p->sex);
		fprintf(fp, "%s ", p->id);
		fprintf(fp, "%s ", p->password);
		fprintf(fp, "%d ", p->math);
		fprintf(fp, "%d ", p->english);
		fprintf(fp, "%d\n", p->pro);
		p = p->next;
	}
	fclose(fp);
	printf("�޸ĳɹ���\n");
}

void revise_math(stu* head, stu* p)
{
	printf("�������µ���ѧ�ɼ���");
	rewind(stdin);
	scanf("%d", &(p->math));
	system("cls");

	FILE* fp;
	fp = fopen("student information.txt", "w");
	p = head->next;
	while (p != NULL)
	{
		fprintf(fp, "%s ", p->class);
		fprintf(fp, "%s ", p->num);
		fprintf(fp, "%s ", p->name);
		fprintf(fp, "%s ", p->sex);
		fprintf(fp, "%s ", p->id);
		fprintf(fp, "%s ", p->password);
		fprintf(fp, "%d ", p->math);
		fprintf(fp, "%d ", p->english);
		fprintf(fp, "%d\n", p->pro);
		p = p->next;
	}
	fclose(fp);
	printf("�޸ĳɹ���\n");
}

void revise_english(stu* head, stu* p)
{
	printf("�������µ�Ӣ��ɼ���");
	rewind(stdin);
	scanf("%d", &(p->english));
	system("cls");

	FILE* fp;
	fp = fopen("student information.txt", "w");
	p = head->next;
	while (p != NULL)
	{
		fprintf(fp, "%s ", p->class);
		fprintf(fp, "%s ", p->num);
		fprintf(fp, "%s ", p->name);
		fprintf(fp, "%s ", p->sex);
		fprintf(fp, "%s ", p->id);
		fprintf(fp, "%s ", p->password);
		fprintf(fp, "%d ", p->math);
		fprintf(fp, "%d ", p->english);
		fprintf(fp, "%d\n", p->pro);
		p = p->next;
	}
	fclose(fp);
	printf("�޸ĳɹ���\n");
}

void revise_pro(stu* head, stu* p)
{
	printf("�������µĳ�����Ƴɼ���");
	rewind(stdin);
	scanf("%d", &(p->pro));
	system("cls");

	FILE* fp;
	fp = fopen("student information.txt", "w");
	p = head->next;
	while (p != NULL)
	{
		fprintf(fp, "%s ", p->class);
		fprintf(fp, "%s ", p->num);
		fprintf(fp, "%s ", p->name);
		fprintf(fp, "%s ", p->sex);
		fprintf(fp, "%s ", p->id);
		fprintf(fp, "%s ", p->password);
		fprintf(fp, "%d ", p->math);
		fprintf(fp, "%d ", p->english);
		fprintf(fp, "%d\n", p->pro);
		p = p->next;
	}
	fclose(fp);
	printf("�޸ĳɹ���\n");
}

void revise_student(stu* head)
{
	stu* p;
	int select = 0;
	char arr[15];
	//�޸�ѧ����Ϣʱ��Ѱ�Ҹ�ѧ����ѧ���Ƿ����
	//�������ٿ�ʼ����ѡ���޸�
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%s", arr);
	system("cls");
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(arr, p->num) == 0)
			break;
		else
			p = p->next;
	}
	if (p == NULL)
	{
		printf("���޴���!\n");
	}
	else
	{
		printf("���ҳɹ���\n");
		do
		{
			//do while�ṹǶ��Switch�ṹ������һ��ѡ��ֲ���
			revise_menu();
			printf("��ѡ����Ҫ�޸ĵ���Ϣ���˳�:");
			scanf("%d", &select);
			switch (select)
			{
			case 1:
				revise_password(head,p);
				break;
			case 2:
				revise_math(head, p);
				break;
			case 3:
				revise_english(head, p);
				break;
			case 4:
				revise_pro(head, p);
				break;
			case 0:
				break;
			}
		} while (select);
		
	}
}

void qurey_num(stu* head)
{
	char arr[15];
	printf("��������Ҫ��ѯ��ѧ�ţ�");
	scanf("%s", arr);
	system("cls");
	stu* p = head->next;
	//�������в�ѯ�Ƿ���ڸ�ѧ��ѧ��
	while (p != NULL)
	{
		if (strcmp(arr, p->num) == 0)
			break;
		else
			//ָ����һ������
			p = p->next;
	}
	if (p == NULL)
	{
		printf("���޴���!\n");
	}
	//�����ҵ�����ӡ��������ѧ����Ϣ
	else
	{
		printf("���ҳɹ���\n");
		printf("�༶��%s��������%-10s\n��ѧ�ɼ���%-3d��Ӣ��ɼ���%-3d��������Ƴɼ���%-3d��\n",p->class ,p->name, p->math, p->english, p->pro);
	}
}

void query_name(stu* head)
{
	{
		char arr[15];
		printf("��������Ҫ��ѯ��������");
		scanf("%s", arr);
		system("cls");
		stu* p = head->next;
		while (p != NULL)
		{
			if (strcmp(arr, p->name) == 0)
				break;
			else
				p = p->next;
		}
		if (p == NULL)
		{
			printf("���޴���!\n");
		}
		else
		{
			printf("���ҳɹ���\n");
			printf("�༶��%s��������%-10s\n��ѧ�ɼ���%-3d��Ӣ��ɼ���%-3d��������Ƴɼ���%-3d��\n", p->class, p->name, p->math, p->english, p->pro);
		}
	}
}

void query_student(stu* head)
{
	int select = 0;
	do
	{
		select_menu();
		printf("��ѡ�������ʽ��");
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			qurey_num(head);
			break;
		case 2:
			query_name(head);
			break;
		case 0:
			break;
		default:
			printf("���벻�Ϸ���\n");
			break;
		}

	} while (select);
}

void view_menu()
{
	printf("=============\n");
	printf("=====1��=====\n");
	printf("=====2��=====\n");
	printf("=====0�˳�===\n");
	printf("=============\n");
}

void subject_menu()
{
	printf("=====================\n");
	printf("========1 ��ѧ=======\n");
	printf("========2 Ӣ��=======\n");
	printf("======3 �������=====\n");
	printf("========0 �˳�=======\n");
	printf("=====================\n");
}

void math_situation(stu* head,int n)
{
	stu* p = head->next;
	char arr[12];
	int count = 0;
	int math_aver = 0;
	int Max = 0;
	int Min = 101;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	//��������Ĳ�ͬ�༶���Σ�ʹarr����洢��ͬ����
	if (n == 1)
	{
		strcpy(arr,"class1");
	}
	else
		strcpy(arr, "class2");
	while (p != NULL)
	{
		//�жϸ�����İ༶��Ϣ
		if (strcmp(p->class, arr) == 0)
		{
			math_aver = math_aver + p->math;
			if (p->math > Max)
				Max = p->math;
			if (p->math < Min)
				Min = p->math;
			count++;
			if (p->math > 90)
				a++;
			else if (p->math > 80)
				b++;
			else if (p->math > 70)
				c++;
			else if (p->math > 60)
				d++;
			else
				e++;
		}
		p = p->next;
	}
	printf("%d�ࣺ��ѧ��߷֣�%d����ѧ��ͷ֣�%d����ѧƽ���֣�%.2f.\n\n",n,Max,Min,(float)math_aver/count);
	printf("�ɼ��ֲ���100-90:����:%d,����:%.2f\n\n90-80����:%d,����:%.2f\n\n80-70:����:%d,����:%.2f\n\n70-60:����:%d,����:%.2f\n\n60-0:����%d,����:%.2f\n",a,(float)a/count, b, (float)b / count, c,(float)c / count,d,(float)d/count,e, (float)e / count);
}

void english_situation(stu* head,int n)
{
	stu* p = head->next;
	char arr[12];
	int count = 0;
	int english_aver = 0;
	int Max = 0;
	int Min = 101;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	if (n == 1)
	{
		strcpy(arr, "class1");
	}
	else
		strcpy(arr, "class2");
	while (p != NULL)
	{
		if (strcmp(p->class, arr) == 0)
		{
			english_aver = english_aver + p->english;
			if (p->english > Max)
				Max = p->english;
			if (p->english < Min)
				Min = p->english;
			count++;
			if (p->english > 90)
				a++;
			else if (p->english > 80)
				b++;
			else if (p->english > 70)
				c++;
			else if (p->english > 60)
				d++;
			else
				e++;
		}
		p = p->next;
	}
	printf("%d��Ӣ����߷֣�%d��Ӣ����ͷ֣�%d��Ӣ��ƽ���֣�%.2f.\n\n",n, Max, Min, (float)english_aver / count);
	printf("�ɼ��ֲ���100-90:����:%d,����:%.2f\n\n90-80����:%d,����:%.2f\n\n80-70:����:%d,����:%.2f\n\n70-60:����:%d,����:%.2f\n\n60-0:����%d,����:%.2f\n", a, (float)a / count, b, (float)b / count, c, (float)c / count, d, (float)d / count, e, (float)e / count);
}

void pro_situation(stu* head,int n)
{
	stu* p = head->next;
	char arr[12];
	int count = 0;
	int pro_aver = 0;
	int Max = 0;
	int Min = 101;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	if (n == 1)
	{
		strcpy(arr, "class1");
	}
	else
		strcpy(arr, "class2");
	while (p != NULL)
	{
		if (strcmp(p->class, arr) == 0)
		{
			pro_aver = pro_aver + p->pro;
			if (p->pro > Max)
				Max = p->pro;
			if (p->pro < Min)
				Min = p->pro;
			count++;
			if (p->pro > 90)
				a++;
			else if (p->pro > 80)
				b++;
			else if (p->pro > 70)
				c++;
			else if (p->pro > 60)
				d++;
			else
				e++;
		}
		p = p->next;
	}
	printf("%d�ࣺ���������߷֣�%d�����������ͷ֣�%d���������ƽ���֣�%.2f.\n\n",n, Max, Min, (float)pro_aver / count);
	printf("�ɼ��ֲ���100-90:����:%d,����:%.2f\n\n90-80����:%d,����:%.2f\n\n80-70:����:%d,����:%.2f\n\n70-60:����:%d,����:%.2f\n\n60-0:����%d,����:%.2f\n", a, (float)a / count, b, (float)b / count, c, (float)c / count, d, (float)d / count, e, (float)e / count);
}

void view_class1(stu* head)
{
	int n = 1;
	int select = 0;
	do
	{
		subject_menu();
		printf("��ѡ��ָ���Ŀ�Ŀ��");
		rewind(stdin);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			math_situation(head,n);
			break;
		case 2:
			english_situation(head,n);
			break;
		case 3:
			pro_situation(head,n);
			break;
		case 0:
			break;
		default:
			printf("���벻�Ϸ���\n");
			break;
		}
	} while (select);
	
}

void view_class2(stu* head)
{
	int n = 2;
	int select = 0;
	do
	{
		subject_menu();
		printf("��ѡ��ָ���Ŀ�Ŀ��");
		rewind(stdin);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			math_situation(head,n);
			break;
		case 2:
			english_situation(head,n);
			break;
		case 3:
			pro_situation(head,n);
			break;
		case 0:
			break;
		default:
			printf("���벻�Ϸ���\n");
			break;
		}
	} while (select);
}

void view(stu* head)
{
	int select = 0;
	do
	{
		view_menu();
		printf("��ѡ��ָ���İ༶��");
		rewind(stdin);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			view_class1(head);
			break;
		case 2:
			view_class2(head);
			break;
		case 0:
			break;
		default:
			printf("���벻�Ϸ���\n");
			break;
		}
	} while (select);
}

void all_student(stu* head)
{
	stu* p;
	p = head->next;
	while (p != NULL)
	{
		printf("%s  ", p->class);
		printf("%s  ", p->num);
		printf("%-10s  ", p->name);
		printf("%-8s  ", p->sex);
		printf("%s  ", p->id);
		printf("%-10s  ", p->password);
		printf("%-3d  ", p->math);
		printf("%-3d  ", p->english);
		printf("% -3d\n", p->pro);
		p = p->next;
	}
}

void change_manager()
{
	 char manager_num[20];
	 rewind(stdin);
	 printf("���������Ա�µ��˺ţ�");
	 scanf("%s", manager_num);
	 char manager_pass[20];
	 printf("���������Ա�µ����룺");
	 scanf("%s", manager_pass);
	 FILE* fp;
	 fp = fopen("manager information.txt", "w");
	 rewind(stdin);
	 fprintf(fp, "%s ", manager_num);
	 fprintf(fp, "%s", manager_pass);
	 fclose(fp);
	 printf("�޸ĳɹ���\n");
}

void manager(stu* head,int* num)
{
	int count = 0;
	char manager_num[20] ;
	char manager_pass[20] ;
	//���ļ���д�����Ա���˺ź�����
	FILE* fp;
	fp = fopen("manager information.txt", "r");
	rewind(stdin);
	fscanf(fp, "%s", manager_num);
	fscanf(fp, "%s", manager_pass);
	fclose(fp);
	char arr1[10];
	char arr2[10];
	//��¼ʱ�����˺ź�����
	//�ж�������˺�����ʹ洢���Ƿ���
	while (1)
	{
		printf("���������Ա�˺ţ�");
		rewind(stdin);
		scanf("%s", arr1);
		rewind(stdin);
		printf("���������Ա���룺");
		scanf("%s", arr2);
		system("cls");
		count++;
		if (strcmp(arr1, manager_num) == 0 && strcmp(arr2, manager_pass) == 0)
		{
			printf("��½�ɹ���\n");
			break;
		}
		else
			printf("��������˺Ż��������\n");
		if (count >= 3)
		{
			printf("�㲻���й���ԱȨ�ޣ�\n");
			break;
		}
	}

	int select = 0;
	do
	{
		manager_menu();
		printf("���������ѡ��");
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			add_student(head);
			(*num)++;
			fp = fopen("number.txt", "w");
			fprintf(fp, "%d", *num);
			fclose(fp);
			break;
		case 2:
			query_student(head);
			break;
		case 3:
			delete_student(head,num);
			fp = fopen("number.txt", "w");
			fprintf(fp, "%d", *num);
			fclose(fp);
			break;
		case 4:
			revise_student(head);
			break;
		case 5:
			view(head);
			break;
		case 6:
			all_student(head);
			break;
		case 7:
			change_manager();
			break;
		case 0:
			break;
		default:
			printf("�����벻�Ϸ������������룡\n");
			break;
		}
	} while (select);

}

void student_menu()
{
	printf("==========================\n");
	printf("========1 ��ѧ�ɼ�========\n");
	printf("========2 Ӣ��ɼ�========\n");
	printf("========3 ������Ƴɼ�====\n");
	printf("========4 ȫ���ɼ�========\n");
	printf("========5 �޸�����========\n");
	printf("========0 �˳�============\n");
	printf("==========================\n");
}

void change_stupass(stu* head,stu* p)
{
	//�ı��ѧ�ŵ�����
	printf("�������µ����룺");
	scanf("%s", &(p->password));

	FILE* fp;
	fp = fopen("student information.txt", "w");
	p = head->next;
	//����д��ѧ����Ϣ
	while (p != NULL)
	{
		fprintf(fp, "%s ", p->class);
		fprintf(fp, "%s ", p->num);
		fprintf(fp, "%s ", p->name);
		fprintf(fp, "%s ", p->sex);
		fprintf(fp, "%s ", p->id);
		fprintf(fp, "%s ", p->password);
		fprintf(fp, "%d ", p->math);
		fprintf(fp, "%d ", p->english);
		fprintf(fp, "%d\n", p->pro);
		p = p->next;
	}
	fclose(fp);
	printf("�޸ĳɹ���\n");
}

void student(stu* head)
{
	int count = 0;
	stu* p = head->next;
	char num[15];
	char password[10];
	while (1)
	{
		if (count > 3)
		{
			printf("�㲻���и�ѧ��Ȩ�ޣ�\n");
			break;
		}
		//��¼ʱ����ѧ�ź����룬����ѧ��Ѱ�������е�������Ϣ
		//�ж����������ʹ洢���Ƿ��Ǻ�
		printf("���������ѧ�ţ�");
		scanf("%s", num);
		rewind(stdin);
		printf("������������룺");
		scanf("%s", password);
		system("cls");
		count++;
		while (p != NULL)
		{
			if (strcmp(num, p->num) == 0)
				break;
			p = p->next;
		}
		if (p == NULL)
			printf("�������ѧ������\n");
		else
		{
			if (strcmp(password, p->password) == 0)
			{
				printf("��¼�ɹ���\n");
				break;
			}
			else
			{
				printf("�������! \n");
			}
		}
	}

	int select = 0;
	do
	{
		student_menu();
		printf("���������ѡ��");
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			printf("��ѧ�ɼ�Ϊ��%d\n", p->math);
			break;
		case 2:
			printf("Ӣ��ɼ�Ϊ��%d\n", p->english);
			break;
		case 3:
			printf("������Ƴɼ�Ϊ��%d\n", p->pro);
		case 4:
			printf("��ѧ�ɼ���%d��", p->math);
			printf("Ӣ��ɼ���%d��", p->english);
			printf("������Ƴɼ���%d\n", p->pro);
			break;
		case 5:
			change_stupass(head,p);
			break;
		case 0:
			break;
		default:
			printf("�����벻�Ϸ������������룡\n");
			break;
		}
	} while (select);
}

int main()
{
	int num = 0;
	//���ļ���Ϊ�˴洢���ܱ仯��ѧ��������ʹ��һ���ļ������洢������Ϣ
	//ÿ�δ򿪳��򶼴��ļ���д��ѧ��������Ϣ
	FILE* fp;
	fp = fopen("number.txt", "r");
	fscanf(fp,"%d", &num);
	fclose(fp);
	//����ѧ������������Ӧ���ȵ�����
	stu* head=Creatlink(num);
	//������Ϣд��
	Fileread(head,num);
	int select = 0;
	do
	{
		menu();
		printf("���������ѡ��");
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			manager(head,&num);
			break;
		case 2:
			student(head);
			break;
		case 0:
			break;
		default:
			printf("�����벻�Ϸ������������룡\n");
			break;
		}
	} while (select);
	//ÿ�ιرճ��������д��ѧ��������Ϣ
	fp = fopen("number.txt", "w");
	fprintf(fp, "%d", num);
	fclose(fp);

	return 0;
}
