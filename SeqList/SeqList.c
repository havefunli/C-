#define  _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SLInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}

	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// 21£º15¼ÌÐø
void SLPushBack(SL* ps, SLDataType x)
{
	// À©ÈÝ
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		ps->a = tmp;
		ps->capacity *= 2;
	}

	//ps->a[ps->size] = x;
	//ps->size++;
	ps->a[ps->size++] = x;
}

void SLPopBack(SL* ps)
{
	// ±©Á¦¼ì²é
	assert(ps->size > 0);

	// ÎÂÈáµÄ¼ì²é
	//if (ps->size == 0)
		//return;

	//ps->a[ps->size - 1] = 0;
	ps->size--;
}

void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);