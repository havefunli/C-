#define  _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


void TestSeqList1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);
	SLPushBack(&s, 8);
	SLPushBack(&s, 9);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	//SLPopBack(&s);
	SLPrint(&s);

	SLPushBack(&s, 10);
	SLPushBack(&s, 20);
	SLPrint(&s);

	SLDestroy(&s);
}

int main()
{
	TestSeqList1();

	/*int* p = (int*)malloc(sizeof(int) * 4);

	if (p == NULL)
	{
		perror("malloc fail:");
	}
	int* ptr = p;

	for (int i = 0; i < 4; i++)
	{
		ptr[i] = i + 1;
	}

	for (int k = 0; k < 4; k++)
	{
		printf("%d ", ptr[k]);
	}*/

	return 0;
}