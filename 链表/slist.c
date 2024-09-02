#define  _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* ptr = (SListNode* )malloc(sizeof(SListNode));
	if (ptr == NULL)
	{
		perror("BuySlistNode_malloc:");
		return NULL;
	}

	ptr->data = x;
	ptr->next = NULL;

	return  ptr;
}

void SListPrint(SListNode* plist)
{
	SListNode* ptr = plist;

	while (ptr)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* ptr = *pplist;

		while (ptr->next)
		{
			ptr = ptr->next;
		}

		ptr->next = newnode;
	}
}

void SListPushFront(SListNode** pplist, SLTDateType  x)
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		(*pplist)==NULL;
	}
	else
	{
		SListNode* ptr = *pplist;

		while(ptr->next->next != NULL)
		{
			ptr = ptr->next;
		}

		free(ptr->next);
		ptr->next = NULL;
	}
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* ptr = (*pplist)->next;
		free(*pplist);
		*pplist = ptr;
	}
}
