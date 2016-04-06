#include <stdio.h>
#include <stdlib.h>

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
	int origin[6] = { 5,46,25,98,75,14 };
	bucket_sort(origin);
	for (int i = 1; i <= origin[0]; i++)
	{
		printf("%d\t",origin[i]);
	}
}

/*************************************************
Function: bucket_sort(int* origin)
Description: 对数组元素在0-99范围内的数组进行排序
Calls: insert_by_data(LNode*, LNode*)
Called By: main()
Table Accessed: NULL
Table Updated: NULL
Input:  int* origin->数组首地址
Output: NULL
Return: NULL
Others: 要用malloc()申请origin[0]个LNode大小的空间
		origin[0] = 数组origin中除origin[0]外元素个数
*************************************************/
void bucket_sort(int* origin)
{
	LNode father[10];
	LNode* son = (LNode*)malloc(origin[0] * sizeof(LNode));
	int k = 1;

	//将origin中的值复制到son的各个结点的data中
	for (int i = 0; i < origin[0]; i++)
	{
		(son + i)->data = origin[i + 1];
		(son + i)->next = NULL;
	}

	//初始化father数组
	for (int i = 0; i < 10; i++)
	{
		father[i].next = NULL;
	}
	
	//利用insert_by_data()，将son中结点插入father之后
	for (int i = 0; i < origin[0]; i++)
	{
		int decade = (son + i)->data / 10;
		insert_by_data((father + decade), (son + i));
	}

	//将son中data值从小到大复制到origin
	for (int i = 0; i < 10 && k <= origin[0]; i++)
	{
		if (!father[i].next)
			continue;

		LNode* temp = father[i].next;
		while (temp->next)
		{
			origin[k++] = temp->data;
			temp = temp->next;
		}
		origin[k++] = temp->data;
	}

	free(son);
}

/*************************************************
Function: insert_by_data(LNode* head, LNode* node)
Description: 将node按照从小到大的顺序插入到head之后
Calls: NULL
Called By: bucket_sort()
Table Accessed: NULL
Table Updated: NULL
Input:  LNode* head->头结点
		LNode* node->待插入的结点
Output: NULL
Return: LNode* head->插入的node结点之前的那个结点的地址,即head->next = node
Others: NULL
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