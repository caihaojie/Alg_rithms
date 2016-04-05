#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct LNode
{
	int data;
	struct LNode* next;
};
typedef struct LNode LNode;
void bucket_sort(int*);
LNode* insert_by_data(LNode*, LNode*);

void main()
{
	/*
	LNode test[5];
	test[0].data = 50;
	test[1].data = 10;
	test[2].data = 40;
	test[3].data = 50;
	test[4].data = 60;
	test[0].next = test+1;
	test[1].next = test + 2;
	test[2].next = test + 3;
	test[3].next = test + 4;
	test[4].next = NULL;
	insert_by_data(test, test);
	LNode* i = test+1;
	while (i->next)
	{
		printf("%d\t", i->data);
		i = i->next;
	}
	
	printf("%d\t", i->data);
	*/
	/*
	LNode A, B;
	A.data = 10;
	B.data = 100;
	A.next = NULL;
	B.next = NULL;
	LNode* C = insert_by_data(&B, &A);
	printf("%d\t",C->data);
	C = C->next;
	printf("%d\t", C->data);
	*/

}

/*************************************************
Function: counting_sort()
Description: 从小到大对origin进行计数排序，数组order为排序结果
Calls: NULL
Called By: main()
Table Accessed: NULL
Table Updated: NULL
Input:  int* origin->待排序的数列首地址
		int* order->排序后的数组首地址
		int max->数组origin中元素的最大值
Output: NULL
Return: NULL
Others: 要用malloc()申请max个int大小的空间
		数组A中每个元素均大于等于0，小于等于max
		origin[0] = 数组origin中除origin[0]外元素个数
		order[0] = 数组order中除order[0]外元素个数,order[0] = origin[0]
*************************************************/
void bucket_sort(int* origin)
{
	LNode father[10];
	LNode* son = (LNode*)malloc(origin[0] * sizeof(LNode));

	for (int i = 0; i <= origin[0]; i++)
	{
		(son + i)->data = origin + i + 1;
		(son + i)->next = NULL;
	}

	for (int i = 0; i < 9; i++)
	{
		father[i].next = father + i + 1;
	}
	father[9].next = NULL;

}

/*************************************************
Function: counting_sort()
Description: 从小到大对origin进行计数排序，数组order为排序结果
Calls: NULL
Called By: main()
Table Accessed: NULL
Table Updated: NULL
Input:  int* origin->待排序的数列首地址
int* order->排序后的数组首地址
int max->数组origin中元素的最大值
Output: NULL
Return: NULL
Others: 要用malloc()申请max个int大小的空间
数组A中每个元素均大于等于0，小于等于max
origin[0] = 数组origin中除origin[0]外元素个数
order[0] = 数组order中除order[0]外元素个数,order[0] = origin[0]
*************************************************/
LNode* insert_by_data(LNode* head, LNode* node)
{
	while (head->next)
	{
		if (head->next->data > node->data)
		{
			node->next = head->next;
			head->next = node;
			return head;
		}
		else {
			head = head->next;
		}
	}

	head->next = node;
	return head;
}