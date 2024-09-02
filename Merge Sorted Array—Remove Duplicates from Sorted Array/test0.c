#define  _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    int nums1[1] = {1}, m = 1;
//    int  nums2[1] = {1}, n = 0;
//
//    int nums3[200] = { 0 };
//    int  i = 0, k = 0;
//    int count = 0;
//
//    while (i < m && k < n)
//    {
//        if (nums2[k] >= nums1[i])
//        {
//            nums3[count] = nums1[i];
//            i++;
//            count++;
//        }
//        else
//        {
//            nums3[count] = nums2[k];
//            k++;
//            count++;
//        }
//    }
//
//    if (i == m)
//    {
//        for (k; k < n; k++)
//        {
//            nums3[count] = nums2[k];
//            count++;
//        }
//    }
//    else
//    {
//        for (i; i < m; i++)
//        {
//            nums3[count] = nums1[i];
//            count++;
//        }
//    }
//
//    for (i = 0; i < m + n; i++)
//    {
//        nums1[i] = nums3[i];
//    }
//
//    for (i = 0; i < m + n; i++)
//    {
//        printf("%d  ", nums3[i]);
//    }
//
//    return 0;
//}

#include<stdio.h>

//void change(char* ps)
//{
//	printf("%p\n", &ps);
//}
//
//int main()
//{
//	/*int i, sum, j = 0;
//	for (i = 104; i <= 1000; i++)
//	{
//		sum = i / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10;
//		if (sum == 5)
//		{
//			printf("%d,", i);
//			j++;
//		}
//	}
//	printf("¹²ÓÐ%d¸ö\n", j);*/
//
//	char arr[10] = "abcd";
//	/*char* ptr = &arr[0];
//	printf("%c\n", *ptr);*/
//
//	change(arr);
//	printf("%p", &arr);
//	return 0;
//}

//void place(char* ps)
//{
//	printf("%c\n",++ps[0]);
//}
//
//int main()
//{
//	//char a[10] = {'a','b','c'};
//	//char* ptr = a;
//
//	//printf("%c\n", ptr[0]);
//	//place(ptr);
//
//	char ptr[10] = "abcd";
//	printf("%c\n", ptr);
//
//	return 0;
//}

void my_free(int* ps)
{
	free(ps);
	/*printf("%p", ps);*/
}


int main()
{
	int a = 1;
	int* ptr = &a;
	printf("%p\n", ptr);

	my_free(ptr);

	printf("%p", ptr);

	return 0;
}
