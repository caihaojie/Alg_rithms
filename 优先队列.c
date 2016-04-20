#include <stdio.h>
#include <limits.h>

int heap_maxinum();
int heap_extract_max();
void heap_increase_key();
void max_heap_insert();
void max_heapify();
void build_max_heap();

void main() 
{
	int target[7] = { 6,5,1,9,4,6,3 };
	build_max_heap(target);
	printf("原序列:\n");
	for (int i = 1; i <= target[0]; i++)
	{
		printf("%d\t", target[i]);
	}
	printf("\n最大值:%d\n",heap_maxinum(target));
	/*
	printf("增大某个值之后:\n");
	heap_increase_key(target, 2, 10);
	for (int i = 1; i <= target[0]; i++)
	{
		printf("%d\t", target[i]);
	}
	*/
	/*
	printf("去除最大值之后:\n");
	heap_extract_max(target);
	for (int i = 1; i <= target[0]; i++)
	{
		printf("%d\t", target[i]);
	}
	*/
}

//返回最大值，即head[1]
int heap_maxinum(int* head)
{
	return head[1];
}

/*************************************************
Function: heap_extract_max(int* head)
Description: 将head[]中的最大值排除出head[],再保持head[]为最大堆
Calls: max_heapify()
Called By: main()
Input:  int* head->数组首地址
Output: NULL
Return: head[]中被剔除的最大值
Others: NULL
*************************************************/
int heap_extract_max(int* head)
{
	//防止溢出
	if (head[0] < 1)
	{
		printf("队列为空");
 		exit(-1);
	}

	int max = head[1];
	head[1] = head[head[0]];
	head[0]--;
	max_heapify(head, 1);
	return max;
}

/*************************************************
Function: max_heapify(int *head, int i)
Description: 构造最大堆
Calls: max_heapify()
Called By: build_max_heap(),heap_extract_max(),max_heapify()
Input:  int* head->数组首地址
		int i->数组中第i个元素（head[0]默认是第0个）
Output: NULL
Return: NULL
Others: 与堆排序.c中的max_heapify()函数基本相同
*************************************************/
void max_heapify(int *head, int i)
{
	int L = i * 2;
	int R = i * 2 + 1;
	int largest;

	//比较head[i],head[L],head[R]的大小，使head[largest] = max(head[i],head[L],head[R])
	if (L < head[0] && head[L] > head[i])
	{
		largest = L;
	}
	else
	{
		largest = i;
	}

	if (R < head[0] && head[R] > head[i])
	{
		largest = R;
	}

	if (largest != i)
	{
		int temp = head[largest];
		head[largest] = head[i];
		head[i] = temp;
		max_heapify(head, largest);
	}
}

//调用max_heapify(),构建最大堆
void build_max_heap(int* head)
{
	for (int i = head[0]/2; i > 0; i--)
	{
		max_heapify(head, i);
	}
}

/*************************************************
Function: heap_increase_key(int* head, int i, int key)
Description: 将head[i]增加到key
Calls: NULL
Called By: main()
Input:  int* head->数组首地址
		int i->数组中第i个元素（head[0]默认是第0个）
		int key->head[i]的新值
Output: NULL
Return: NULL
Others: 要求key >= head[i]
*************************************************/
void heap_increase_key(int* head, int i, int key)
{
	int temp;
	
	if (key < head[i])
	{
		printf("插入的值小于原有值");
		exit(-1);
	}
	
	head[i] = key;

	while (i > 1 && head[i / 2] < head[i])
	{
		temp = head[i];
		head[i] = head[i / 2];
		head[i / 2] = temp;
		i = i / 2;
	}
}

//向最大堆里面insert一个元素,得先确保数组里面有多余的空间
void max_heap_insert(int* head,int key)
{
	head[0]++;
	head[head[0]] = INT_MIN;
	heap_increase_key(head, head[0], key);
}
