#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "struct.h"
//参数为学生的人数，便于创造相应长度的链表
stu*  Creatlink(int lenth)
{
	//利用头插法创建链表
	stu* head, *p;
	//链表头
	head = (stu* )malloc(sizeof(stu));
	head->next = NULL;
	int i = 0;
	//创建相应长度链表
	while (i < lenth)
	{
		p = (stu* )malloc(sizeof(stu));
		p->next = head->next;
		head->next = p;
		i++;
	}
	//将链表头传回，便于其他函数使用
	return head;
}
//从文件中读取学生的信息并写入链表中
void Fileread(stu* head ,int lenth)
{
	int i = 0;
	stu* p;
	p = head->next;
	//文件指针打开相应文件
	FILE* fp;
	fp = fopen("student information.txt", "r");
	
	rewind(stdin);
	//向链表中依次写入信息
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
		//该链表填充后，指向下一个链表
		p = p->next;
		i++;
	}
	fclose(fp);
}

void menu()
{
	printf("=========================\n");
	printf("=========1 管理员========\n");
	printf("=========2 学生==========\n");
	printf("=========0 退出==========\n");
	printf("=========================\n");
}

void manager_menu()
{
	printf("===============================\n");
	printf("=========1 添加学生信息========\n");
	printf("=========2 查询学生信息========\n");
	printf("=========3 删除学生信息========\n");
	printf("=========4 修改学生信息========\n");
	printf("=========5 浏览学生成绩情况====\n");
	printf("=========6 全部学生信息========\n");
	printf("=========7 修改管理员信息======\n");
	printf("=========0 退出================\n");
	printf("===============================\n");
}

void select_menu()
{
	printf("====================\n");
	printf("=======1 学号=======\n");
	printf("=======2 姓名=======\n");
	printf("=======0 退出=======\n");
	printf("====================\n");
}

void revise_menu()
{
	printf("=======================\n");
	printf("=======1 密码==========\n");
	printf("=======2 数学==========\n");
	printf("=======3 英语==========\n");
	printf("=======4 程序设计======\n");
	printf("=======0 退出==========\n");
	printf("=======================\n");
}

void add_student(stu* head)
{
	stu* p;
	stu* que;
	int i = 0;
	//申请一个链表空间来添加学生信息
	p = (stu*)malloc(sizeof(stu));
	p->next = head->next;
	head->next = p;
	//为避免学号重复，该操作来查重，若重复则重新输入学号
	while (i == 0)
	{
		que = p->next;
		printf("请输入学号：");
		rewind(stdin);
		scanf("%s", &(p->num));
		//在链表中寻找是否存在相同学号
		while (que != NULL)
		{
			if (strcmp(que->num, p->num )==0)
				break;
			que = que->next;
		}
		if (que != NULL)
		{
			printf("该账号已存在！\n");
			i = 0;
		}
		else
			i = 1;
	}
	//在输入前清空键盘缓冲区，避免回车产生输入错误
	rewind(stdin);
	printf("请输入班级：");
	scanf("%s", &(p->class));
	rewind(stdin);
	printf("请输入姓名：");
	scanf( "%s", &(p->name));
	rewind(stdin);
	printf("请输入性别：");
	scanf("%s", &(p->sex));
	rewind(stdin);
	printf("请输入身份证：");
	scanf("%s", &(p->id));
	rewind(stdin);
	printf("请创建密码：");
	scanf("%s", &(p->password));
	rewind(stdin);
	printf("请输入数学成绩：");
	scanf("%d", &(p->math));
	rewind(stdin);
	printf("请输入英语成绩：");
	scanf("%d", &(p->english));
	rewind(stdin);
	printf("请输入设计成绩：");
	scanf("%d", &(p->pro));
	//打开文件，当学生信息有变动时重新写入
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
	printf("添加成功！\n");
	Sleep(1000);
	system("cls");
}
//此次操作中定义了两个结构指针，且一前一后。
//避免删除学生信息也就是释放该链表空间时，丢失该链表以后的全部链表地址
void delete_student(stu* head,int* num)
{
	char arr[15];
	stu* p,*det;
	p = head;
	det = p->next;
	printf("请输入所要删除学生的学号：");
	scanf("%s", arr);
	system("cls");
	//在链表中寻找是否存在要删除的学生号，若存在删除，不存在给出反馈
	while (det != NULL)
	{
		if (strcmp(arr, det->num) == 0)
			break;
		else
		{
			//排雷式向前不断摸进
			p = det;
			det = p->next;
		}
	}
	if (det == NULL)
	{
		printf("查无此人！\n");
	}
	else
	{
		p->next = det->next;
		free(det);
		printf("删除成功！\n");
		//打开文件，当学生信息有变动时重新写入
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
		//学生人数减一
		(*num)--;
	}
}

void revise_password(stu* head,stu* p)
{
	printf("请输入新的密码：");
	rewind(stdin);
	scanf("%s", &(p->password));
	system("cls");

	//打开文件，当学生信息有变动时重新写入
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
	printf("修改成功！\n");
}

void revise_math(stu* head, stu* p)
{
	printf("请输入新的数学成绩：");
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
	printf("修改成功！\n");
}

void revise_english(stu* head, stu* p)
{
	printf("请输入新的英语成绩：");
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
	printf("修改成功！\n");
}

void revise_pro(stu* head, stu* p)
{
	printf("请输入新的程序设计成绩：");
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
	printf("修改成功！\n");
}

void revise_student(stu* head)
{
	stu* p;
	int select = 0;
	char arr[15];
	//修改学生信息时先寻找该学生的学号是否存在
	//若存在再开始根据选择修改
	printf("输入所要修改的学生的学号：");
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
		printf("查无此人!\n");
	}
	else
	{
		printf("查找成功！\n");
		do
		{
			//do while结构嵌套Switch结构来构造一个选择分叉树
			revise_menu();
			printf("请选择所要修改的信息或退出:");
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
	printf("请输入所要查询的学号：");
	scanf("%s", arr);
	system("cls");
	stu* p = head->next;
	//在链表中查询是否存在该学生学号
	while (p != NULL)
	{
		if (strcmp(arr, p->num) == 0)
			break;
		else
			//指向下一个链表
			p = p->next;
	}
	if (p == NULL)
	{
		printf("查无此人!\n");
	}
	//若查找到，打印出该链表学生信息
	else
	{
		printf("查找成功！\n");
		printf("班级：%s，姓名：%-10s\n数学成绩：%-3d，英语成绩：%-3d，程序设计成绩：%-3d。\n",p->class ,p->name, p->math, p->english, p->pro);
	}
}

void query_name(stu* head)
{
	{
		char arr[15];
		printf("请输入所要查询的姓名：");
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
			printf("查无此人!\n");
		}
		else
		{
			printf("查找成功！\n");
			printf("班级：%s，姓名：%-10s\n数学成绩：%-3d，英语成绩：%-3d，程序设计成绩：%-3d。\n", p->class, p->name, p->math, p->english, p->pro);
		}
	}
}

void query_student(stu* head)
{
	int select = 0;
	do
	{
		select_menu();
		printf("请选择检索方式：");
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
			printf("输入不合法！\n");
			break;
		}

	} while (select);
}

void view_menu()
{
	printf("=============\n");
	printf("=====1班=====\n");
	printf("=====2班=====\n");
	printf("=====0退出===\n");
	printf("=============\n");
}

void subject_menu()
{
	printf("=====================\n");
	printf("========1 数学=======\n");
	printf("========2 英语=======\n");
	printf("======3 程序设计=====\n");
	printf("========0 退出=======\n");
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
	//根据输入的不同班级传参，使arr数组存储不同内容
	if (n == 1)
	{
		strcpy(arr,"class1");
	}
	else
		strcpy(arr, "class2");
	while (p != NULL)
	{
		//判断该链表的班级信息
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
	printf("%d班：数学最高分：%d，数学最低分：%d，数学平均分：%.2f.\n\n",n,Max,Min,(float)math_aver/count);
	printf("成绩分布：100-90:人数:%d,比例:%.2f\n\n90-80人数:%d,比例:%.2f\n\n80-70:人数:%d,比例:%.2f\n\n70-60:人数:%d,比例:%.2f\n\n60-0:人数%d,比例:%.2f\n",a,(float)a/count, b, (float)b / count, c,(float)c / count,d,(float)d/count,e, (float)e / count);
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
	printf("%d班英语最高分：%d，英语最低分：%d，英语平均分：%.2f.\n\n",n, Max, Min, (float)english_aver / count);
	printf("成绩分布：100-90:人数:%d,比例:%.2f\n\n90-80人数:%d,比例:%.2f\n\n80-70:人数:%d,比例:%.2f\n\n70-60:人数:%d,比例:%.2f\n\n60-0:人数%d,比例:%.2f\n", a, (float)a / count, b, (float)b / count, c, (float)c / count, d, (float)d / count, e, (float)e / count);
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
	printf("%d班：程序设计最高分：%d，程序设计最低分：%d，程序设计平均分：%.2f.\n\n",n, Max, Min, (float)pro_aver / count);
	printf("成绩分布：100-90:人数:%d,比例:%.2f\n\n90-80人数:%d,比例:%.2f\n\n80-70:人数:%d,比例:%.2f\n\n70-60:人数:%d,比例:%.2f\n\n60-0:人数%d,比例:%.2f\n", a, (float)a / count, b, (float)b / count, c, (float)c / count, d, (float)d / count, e, (float)e / count);
}

void view_class1(stu* head)
{
	int n = 1;
	int select = 0;
	do
	{
		subject_menu();
		printf("请选择指定的科目：");
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
			printf("输入不合法！\n");
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
		printf("请选择指定的科目：");
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
			printf("输入不合法！\n");
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
		printf("请选择指定的班级：");
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
			printf("输入不合法！\n");
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
	 printf("请输入管理员新的账号：");
	 scanf("%s", manager_num);
	 char manager_pass[20];
	 printf("请输入管理员新的密码：");
	 scanf("%s", manager_pass);
	 FILE* fp;
	 fp = fopen("manager information.txt", "w");
	 rewind(stdin);
	 fprintf(fp, "%s ", manager_num);
	 fprintf(fp, "%s", manager_pass);
	 fclose(fp);
	 printf("修改成功！\n");
}

void manager(stu* head,int* num)
{
	int count = 0;
	char manager_num[20] ;
	char manager_pass[20] ;
	//从文件中写入管理员的账号和密码
	FILE* fp;
	fp = fopen("manager information.txt", "r");
	rewind(stdin);
	fscanf(fp, "%s", manager_num);
	fscanf(fp, "%s", manager_pass);
	fclose(fp);
	char arr1[10];
	char arr2[10];
	//登录时输入账号和密码
	//判断输入的账号密码和存储的是否吻
	while (1)
	{
		printf("请输入管理员账号：");
		rewind(stdin);
		scanf("%s", arr1);
		rewind(stdin);
		printf("请输入管理员密码：");
		scanf("%s", arr2);
		system("cls");
		count++;
		if (strcmp(arr1, manager_num) == 0 && strcmp(arr2, manager_pass) == 0)
		{
			printf("登陆成功！\n");
			break;
		}
		else
			printf("您输入的账号或密码错误！\n");
		if (count >= 3)
		{
			printf("你不具有管理员权限！\n");
			break;
		}
	}

	int select = 0;
	do
	{
		manager_menu();
		printf("请输入你的选择：");
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
			printf("该输入不合法，请重新输入！\n");
			break;
		}
	} while (select);

}

void student_menu()
{
	printf("==========================\n");
	printf("========1 数学成绩========\n");
	printf("========2 英语成绩========\n");
	printf("========3 程序设计成绩====\n");
	printf("========4 全部成绩========\n");
	printf("========5 修改密码========\n");
	printf("========0 退出============\n");
	printf("==========================\n");
}

void change_stupass(stu* head,stu* p)
{
	//改变该学号的密码
	printf("请输入新的密码：");
	scanf("%s", &(p->password));

	FILE* fp;
	fp = fopen("student information.txt", "w");
	p = head->next;
	//重新写入学生信息
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
	printf("修改成功！\n");
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
			printf("你不具有该学生权限！\n");
			break;
		}
		//登录时输入学号和密码，根据学号寻找链表中的密码信息
		//判断输入的密码和存储的是否吻合
		printf("请输入你的学号：");
		scanf("%s", num);
		rewind(stdin);
		printf("请输入你的密码：");
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
			printf("你输入的学号有误！\n");
		else
		{
			if (strcmp(password, p->password) == 0)
			{
				printf("登录成功！\n");
				break;
			}
			else
			{
				printf("密码错误! \n");
			}
		}
	}

	int select = 0;
	do
	{
		student_menu();
		printf("请输入你的选择：");
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			printf("数学成绩为：%d\n", p->math);
			break;
		case 2:
			printf("英语成绩为：%d\n", p->english);
			break;
		case 3:
			printf("程序设计成绩为：%d\n", p->pro);
		case 4:
			printf("数学成绩：%d，", p->math);
			printf("英语成绩：%d，", p->english);
			printf("程序设计成绩：%d\n", p->pro);
			break;
		case 5:
			change_stupass(head,p);
			break;
		case 0:
			break;
		default:
			printf("该输入不合法，请重新输入！\n");
			break;
		}
	} while (select);
}

int main()
{
	int num = 0;
	//打开文件，为了存储可能变化的学生人数，使用一个文件单独存储人数信息
	//每次打开程序都从文件中写入学生人数信息
	FILE* fp;
	fp = fopen("number.txt", "r");
	fscanf(fp,"%d", &num);
	fclose(fp);
	//根据学生人数创造相应长度的链表
	stu* head=Creatlink(num);
	//链表信息写入
	Fileread(head,num);
	int select = 0;
	do
	{
		menu();
		printf("请输入你的选择：");
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
			printf("该输入不合法，请重新输入！\n");
			break;
		}
	} while (select);
	//每次关闭程序后都重新写入学生人数信息
	fp = fopen("number.txt", "w");
	fprintf(fp, "%d", num);
	fclose(fp);

	return 0;
}
