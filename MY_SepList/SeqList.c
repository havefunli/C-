//#define  _CRT_SECURE_NO_WARNINGS 1
//#include "SeqList.h"
//
//void  SLInit(SL* ps)
//{
//	int* ptr = (int*)malloc(sizeof(int) * SL_Capacity);
//	if (ptr == NULL)
//	{
//		perror("SLInit_malloc:");
//		return 0;
//	}
//	ps = ptr;
//
//	ps->capacity = SL_Capacity;
//	ps->size = 0;
//}
//
//void SLDestroy(SL* ps)
//{
//	free(ps->nums);
//	ps->nums = NULL;
//	ps->size = 0;
//	ps->capacity = 0;
//}
//
//void SLPrint(SL* ps)
//{
//	int i = 0;
//	for (i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->nums[i]);
//	}
//	printf("\n");
//}
//
//void SLPushBack(SL* ps, int x)
//{
//	if (ps->capacity = ps->size)
//	{
//		int* ptr = (int*)malloc(sizeof(int) * ps->capacity * 2);
//		if (ptr == NULL)
//		{
//			perror("SLPushBack_malloc:");
//		}
//		ps = ptr;
//		ps->capacity *= 2;
//	}
//
//	ps->nums[ps->size++] = x;
//}
//
//void SLPopBack(SL* ps)
//{
//	assert(ps->size > 0);
//	ps->size--;
//}