#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int is_idnum(char* p)
{
	int len = 0;
	len = strlen(p);
	//若身份证不满18位，发返回1，再次循环
	if (len != 18)
	{
		printf("你输入的身份证不合法！\n");
		return 1;
	}
	//若身份证满足情况跳出循环
	else
		return 0;
}
//510304200408236737
//将身份证的第7位到10位分别提取出来
//将数字由字符形式转化为整形，以此计算年龄
int cal_age(char* p)
{
	//将字符分别取出
	char age1 = *(p + 6);
	char age2 = *(p + 7);
	char age3 = *(p + 8);
	char age4 = *(p + 9);
	//字符数字转为整形方法为减去一个字符0
	int age = 2022 - (age1 - '0') * 1000 - (age2 - '0') * 100 - (age3 - '0') * 10 - (age4 - '0');
}

int main()
{
	char idnum[20];
	//当输入合法时 ret = 0，结束循环。避免利用错误格式的身份证计算年龄
	int ret = 1;
	while (ret)
	{
		printf("请输入你的身份证号码：");
		scanf("%s", idnum);
		//将储存身份证的字符串首地址传给判断函数
		ret = is_idnum(idnum);
	}
	
	int age = cal_age(idnum);
	printf("你的年龄为：%d", age);

	if (age > 18)
		return 1;
	else
		return 0;
}