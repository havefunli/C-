#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int is_idnum(char* p)
{
	int len = 0;
	len = strlen(p);
	//�����֤����18λ��������1���ٴ�ѭ��
	if (len != 18)
	{
		printf("����������֤���Ϸ���\n");
		return 1;
	}
	//�����֤�����������ѭ��
	else
		return 0;
}
//510304200408236737
//�����֤�ĵ�7λ��10λ�ֱ���ȡ����
//���������ַ���ʽת��Ϊ���Σ��Դ˼�������
int cal_age(char* p)
{
	//���ַ��ֱ�ȡ��
	char age1 = *(p + 6);
	char age2 = *(p + 7);
	char age3 = *(p + 8);
	char age4 = *(p + 9);
	//�ַ�����תΪ���η���Ϊ��ȥһ���ַ�0
	int age = 2022 - (age1 - '0') * 1000 - (age2 - '0') * 100 - (age3 - '0') * 10 - (age4 - '0');
}

int main()
{
	char idnum[20];
	//������Ϸ�ʱ ret = 0������ѭ�����������ô����ʽ�����֤��������
	int ret = 1;
	while (ret)
	{
		printf("������������֤���룺");
		scanf("%s", idnum);
		//���������֤���ַ����׵�ַ�����жϺ���
		ret = is_idnum(idnum);
	}
	
	int age = cal_age(idnum);
	printf("�������Ϊ��%d", age);

	if (age > 18)
		return 1;
	else
		return 0;
}