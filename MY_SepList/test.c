#define  _CRT_SECURE_NO_WARNINGS 1
//#include "SeqList.h"
#include <stdio.h>
int main()
{
	/*TestSeqlist();*/

	int num = 1;
	int* ps = &num;
	int* ptr = &num;

	printf("%d\n ",num);
	free(ps);
	printf("%d\n ", num);

	return 0;
}