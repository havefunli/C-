#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//不使用第三个变量的情况下交换两个变量
//int main()
//{
//	int a = 2;
//	int b = 4;
//	
//	a = a ^ b;
//	将式一的a代入b=a^b^b,一个数异或本身为0，0异或任何数为那个数本身
//	b = b ^ a;
//	同理可得
//	a = b ^ a;
//	printf("a=%d,b=%d", a, b);
//
//	return 0;
//}

//统计二进制中一的个数
//法一：
//int NumberOf1(int n) 
//{
//    int i = 0;
//    int count = 0;
//    //int型变量一共32位
//    for (i; i < 32; i++)
//    {  
//    //当末尾有1时计数
//        if (n & 1 == 1)
//            count++;
//    //向右移动一位，使前一个数成为新的末尾再判断，直至满足32位
//        n >>= 1;
//    }
//
//    return count;
//}

//int NumberOf1(int n)
//{
//    int count = 0;
//    //当n中不存在1就退出循环
//    while (n)
//    {
//        //该操作可以去除该二进制数中的最前面一个1
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

//输入两个整数，求两个整数二进制格式有多少个位不同
//int main()
//{
//	int n = 0, m = 0;
//	int count = 0;
//	scanf("%d %d", &n, &m);
//	//将两个数相同的转化为0，不相同的转化为1，再计算1的个数
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

//矩阵计算
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

//进制转换
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

// 矩阵转置
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

//序列中删除指定数字
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