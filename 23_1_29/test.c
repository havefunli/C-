#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int main()
//{
//	//char a[] = "abc";
//	//char b[] = "bac";
//
//	//int ret = strcmp(a, b);
//	//printf("%d \n", ret);
//
//	/*if (strcmp(a, b) == 0)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//
//	return 0;*/
//
//	//char a[10]="0";
//
//	//int i = 0;
//	//for (i = 0; i < 5; i++)
//	//{
//	//	a[i] = (getchar()!='1');
//	//	//printf("*");
//	//}
//
//	//printf(a);
//}
//
//struct s
//{
//	int a;
//	char b;
//	double c;
//};

//int main()
//{
//	char c = '0';
//	FILE* fp = ("qbc.txt", "r");
//	fscanf(fp, "%c", &c);
//	/*perror("qbc.txt");*/
//	printf("%s");
//
//}

//int add()
//{
//	static int a = 1;
//	return ++a;
//}
//
//
//int main()
//{
//	int num = 0;
//	num = add();
//	printf("%d\n", num);
//	num = add();
//	printf("%d\n", num);
//
//	return 0;
//}

//void add(int* pt)
//{
//	(*pt)++;
//}
//
//int main()
//{
//	int a = 1;
//	int* ptr = &a;
//	add(ptr);
//
//	printf("%d", a);
//}

//int main()
//{
//	struct s 
//	{
//		char c1;
//		int n;
//		char c2;
//	};
//	struct s S = { 0 };
//	char* ptr1 = &S.c1;
//	char* ptr2 = &S.n;
//
//	printf("%d",ptr2-ptr1);
//
//	return 1;
//}

//#include<stdio.h>
//int main() {
//	//unsigned char i = 7;
//	//int j = 0;
//	//for (; i > 0; i -= 3) {
//	//	++j;
//	//	printf("%d \n", i);
//	//}
//	//printf("%d\n", j);
//	//return 0;
//
//	//unsigned char a = 0;
//
//	char arr[] = {"abcdefg"};
//	//printf("%c", *(arr+1));
//
//	char a = 1+'0';
//	printf("%c", a);
//
//	return 0;
//}

//#include <stdio.h>
//
//int separate(int num, char* arr)
//{
//    int i = 0;
//    int count = 0;
//    while (num)
//    {
//        if (count % 3 == 0 && count != 0)
//        {
//            arr[i++] = ',';
//        }
//        arr[i++] = num % 10 + '0';
//        num /= 10;
//        count++;
//    }
//    return i;
//}
//
//int main() 
//{
//    int num = 0;
//    char arr[100] = { 0 };
//    scanf("%d", &num);
//
//    int len = separate(num, arr);
//
//    int i = 0;
//    for (i = len - 1; i >= 0; i--)
//    {
//        printf("%c", arr[i]);
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <string.h>
//
//int main() {
//    /*char des[100] = { 0 };
//    char del[100] = { 0 };
//    gets(des);
//    gets(del);
//
//    int i = 0;
//    int len_des = strlen(des);
//    int len_del = strlen(del);
//    for (i = 0; i < len_des; i++)
//    {
//        int k = 0;
//        for (k = 0; k < len_del; k++)
//        {
//            if (del[k] == des[i])
//                break;
//        }
//        if (k == len_del)
//            printf("%c", des[i]);
//    }
//
//    return 0;*/
//
//
//    int a = 1;
//    char b = 1+'0';
//    if (a == b)
//    {
//        printf("what");
//    }
//    else
//    {
//        printf("no");
//    }
//}

//void rotate(int* nums, int numsSize, int k) {
//    int arr[numsSize] = { 0 };
//
//    for (int i = 0; i < k; i++)
//    {
//        arr[i] = nums[numsSize - 1 - k + i];
//    }
//
//    for (int i = 0; i < numsSize - k; i++)
//    {
//        arr[k - 1 + i] = nums[i];
//    }
//}


#define nums 10
int main()
{

	int arr[nums] = { 0 };
	return 0;
}