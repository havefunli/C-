#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//奇数在前偶数在后的数组
//int main()
//{
//	int num[10];
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &num[i]);
//	}
//
//	int count = 0;
//	int k = 0;
//	for (i = 0; i < 9; i++)
//	{
//		for (k = 0; k < 9 - i; k++)
//		{
//			int temp = 0;
//			if (num[k] % 2 == 0 && num[k + 1] % 2 != 0)
//			{
//				temp = num[k];
//				num[k] = num[k + 1];
//				num[k + 1] = temp;
//				count = 1;
//			}
//		}
//		if (count)
//			break;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", num[i]);
//	}
//
//	return 0;


//int main()
//{
//	int b = 10;
//	int a = 10;
//	const int* p = &a;
//	p = &b;
//	*p = 20;
//}

#include <assert.h>

//int my_strlen(const char* arr)
//{
//	assert(arr != NULL);
//	int i = 0;
//	for (i = 0;arr[i] != '\0'; i++)
//	{
//		;
//	}
//
//	return i;
//}
//
//int main()
//{
//	char arr[10] = "abcdefg";
//	int ret = my_strlen(arr);
//
//	printf("%d", ret);
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int left = 0;
//	int right = 9;
//	while (left < right)
//	{
//		//找偶数的过程
//		if ((left < right) && arr[left] % 2 != 0)
//		{
//			left++;
//		}
//		//找奇数的过程
//		if ((left < right) && arr[right] % 2 != 1)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int temp = 0;
//			temp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = temp;
//		}
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0, m = 0;
//    scanf("%d %d", &n, &m);
//    int arr1[10];
//    int arr2[10];
//    int arr3[20];
//
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//
//    int k = 0, j = 0;
//    i = 0;
//    while (i < n && j < m)
//    {
//        if (arr1[i] < arr2[j])
//        {
//            arr3[k] = arr1[i];
//            k++;
//            i++;
//        }
//        else
//        {
//            arr3[k] = arr2[j];
//            k++;
//            j++;
//        }
//    }
//    if (i == n)
//    {
//        while (j < m)
//        {
//            arr3[k] = arr2[j];
//            j++;
//            k++;
//        }
//    }
//    if (j == m)
//    {
//        while (i < n)
//        {
//            arr3[k] = arr1[i];
//            i++;
//            k++;
//        }
//    }
//
//    for (i = 0; i < m + n; i++)
//    {
//        printf("%d ", arr3[i]);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[n];
//
//
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//
//    int judge = arr[1] - arr[0];
//    int flag = 1;
//
//
//    if (judge != 0)
//    {
//        for (i = 1; i < n - 1; i++)
//        {
//            if ((arr[i + 1] - arr[i]) * judge > 0)
//                flag = 1;
//            else
//            {
//                flag = 0;
//                goto end;
//            }
//        }
//    }
//    else
//    {
//        for (i = 1; i < n - 1; i++)
//        {
//            if ((arr[i + 1] - arr[i]) == 0)
//                flag = 1;
//            else
//            {
//                flag = 0;
//                goto end;
//            }
//        }
//    }
//end:
//    if (flag == 1)
//        printf("sorted");
//    else
//        printf("unsorted");
//
//    return 0;
//}

/*#include <stdio.h>
int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    for (i = 0; i <= 12; i++)
    {
        arr[i] = 0;
        printf("hello bit\n");
    }
    return 0;
}*/ 

#include <assert.h>

void my_copy(char* des ,const char* source)
{
    assert(des && source);

    int i = 0;
    while ((des[i] = source[i]) != '\0')
    {
        i++;
    }
}

int main()
{
    char des[100];
    char source[100];

    int i = 0;
    while ((source[i++]=getchar()) != '\n')
    {
        ;
    }
    i--;
    source[i] = '\0';
    
    my_copy(des, source);
    printf(des);

    return 0;
}