#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��ʹ�õ���������������½�����������
//int main()
//{
//	int a = 2;
//	int b = 4;
//	
//	a = a ^ b;
//	��ʽһ��a����b=a^b^b,һ���������Ϊ0��0����κ���Ϊ�Ǹ�������
//	b = b ^ a;
//	ͬ��ɵ�
//	a = b ^ a;
//	printf("a=%d,b=%d", a, b);
//
//	return 0;
//}

//ͳ�ƶ�������һ�ĸ���
//��һ��
//int NumberOf1(int n) 
//{
//    int i = 0;
//    int count = 0;
//    //int�ͱ���һ��32λ
//    for (i; i < 32; i++)
//    {  
//    //��ĩβ��1ʱ����
//        if (n & 1 == 1)
//            count++;
//    //�����ƶ�һλ��ʹǰһ������Ϊ�µ�ĩβ���жϣ�ֱ������32λ
//        n >>= 1;
//    }
//
//    return count;
//}

//int NumberOf1(int n)
//{
//    int count = 0;
//    //��n�в�����1���˳�ѭ��
//    while (n)
//    {
//        //�ò�������ȥ���ö��������е���ǰ��һ��1
//        n = n & (n - 1);
//        count++;
//    }
//
//    return count;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int ret = NumberOf1(n);
//    printf("%d\n", ret);
//
//    return 0;
//}

// 10 0000 1010

//void prn(int n)
//{
//	int i = 0;
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//	printf("\n");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	prn(n);
//
//	return 0;
//}

//�����������������������������Ƹ�ʽ�ж��ٸ�λ��ͬ
//int main()
//{
//	int n = 0, m = 0;
//	int count = 0;
//	scanf("%d %d", &n, &m);
//	//����������ͬ��ת��Ϊ0������ͬ��ת��Ϊ1���ټ���1�ĸ���
//	n = n ^ m;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//
//	printf("%d", count);
//}

//
//int Numberofmethod(int n)
//{
//    if (n >= 2)
//        return n;
//    else
//    {
//        return Numberofmethod(n - 1) + Numberofmethod(n - 2);
//    }
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//
//    int ret = Numberofmethod(n);
//    printf("%d", ret);
//}//

//#include <stdio.h>
//
//int main()
//{
//    int year = 0;
//    int month = 0;
//    scanf("%d %d", &year, &month);
//
//    int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (month == 2)
//    {
//        if (((year % 100) != 0 && (year % 4 == 0)) || (year % 400 == 0))
//            printf("%d", 29);
//        else
//            printf("%d", 28);
//    }
//    else
//        printf("%d", monthday[month]);
//
//    return 0;
//}

//�������
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int add = 0;
//	scanf("%d %d", &n, &m);
//
//	int i = 0, k = 0;
//	for (i; i < n; i++)
//	{
//		for (k=0; k < m; k++)
//		{
//			int temp = 0;
//			scanf("%d", &temp);
//			if (temp > 0)
//				add += temp;
//		}
//	}
//
//	printf("%d", add);
//
//	return 0;
//}

//����ת��
//int main()
//{
//	int n = 0;
//	int arr[10];
//	scanf("%d", &n);
//
//	int i = 0;
//	for (i; n != 0; i++)
//	{
//		arr[i] = n % 6;
//		n = n / 6;
//	}
//
//	for (--i; i >= 0; i--)
//	{
//		printf("%d", arr[i]);
//	}
//}

// ����ת��
//#include <stdio.h>
//
//int main()
//{
//	int n = 0, m = 0;
//	int arr[100][100];
//	scanf("%d %d", &n, &m);
//
//	int i = 0, k = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (k=0; k < m; k++)
//		{
//			scanf("%d", &arr[i][k]);
//		}
//	}
//
//	for (i = 0; i < m; i++)
//	{
//		for (k = 0; k < n; k++)
//		{
//			printf("%d ", arr[k][i]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//������ɾ��ָ������
int main()
{
    int arr[100];
    int n = 0;
    scanf("%d", &n);

    int i = 0;
    for (i; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int del = 0;
    scanf("%d", &del);

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != del)
        {
            arr[k] = arr[i];
            k++;
        }
    }

    for (i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }
}