#pragma once
typedef struct student
{
	char class[10];
	char num[15];
	char name[15];
	char sex[8];
	char id[20];
	char password[10];
	int math;
	int english;
	int pro;
	struct student* next;
}stu;