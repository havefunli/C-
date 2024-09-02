#define  _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//
//int  change_num(char* p, int len)
//{
//    int i = 0;
//    for (i = 0; i < len; i++)
//    {
//        if ((p[i] - '0') % 2 == 0)
//        {
//            p[i] = '0';
//        }
//        else
//        {
//             p[i] = '1';
//        }
//    }
//
//    int ret = 0;
//    for (i = 0; i < len; i++)
//    {
//        ret += (p[i] - '0') * pow(10, len - i - 1);
//    }
//
//    return ret;
//}
//
//int main()
//{
//    char arr[10];
//    scanf("%s", arr);
//
//    int len = strlen(arr);
//    int ret = change_num(arr, len);
//
//    return 0;
//}


//void triangle() 
//{
//    printf("  *\n");
//    printf(" * *\n");
//    printf("* * *");
//}
//
//#include <stdio.h>
//
//int main() {
//    triangle();
//    triangle();
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 2;
//	float b = 2;
//
//	int c = a + b;
//
//	printf("%d\n", c);
//
//	return 0;
//}

#include <stdio.h>

void judge(char* num,int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		int k = num[i] - '0';
		if (k % 2 == 0)
		{
			num[i] = '0';
		}
		else
		{
			num[i] = '1';
		}
	}
}


//int main()
//{
	//char num[100] = { 0 };
	//scanf("%s", num);
	//int len = strlen(num);

	//judge(num,len);

	//printf(num);
	//return 0;

//	int a = 1;
//	int b = 2;
//	scanf("%d",&a);
//
//	printf("%d %d\n", a, b, a);
//}

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* e1, const void* e2)
{
	return *(int*)e2 - *(int*)e1;
}

int main()
{
	/*int arr[5] = { 1,2,3,4,5 };
	int len = 5;

	qsort(arr, len, sizeof(arr[0]),cmp);

	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}*/

	char arr[] = "abcd";
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%c ", arr);
		arr++;
	}

	return 0;
}
