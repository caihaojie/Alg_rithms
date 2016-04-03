#include <stdio.h>
#include <stdlib.h>

int left();
int right();
void build_max_heap();
void max_heapify();
void heap_sort();

void main()
{
	int target[7] = {6,5,3,4,9,8,1};//为了便于之后操作，第一个元素是数组长度->heap_size
	int length = target[0];
	heap_sort(target);
	for (int i = 1; i <= length; i++)
	{
		printf("%d\t", target[i]);
	}
}

int left(int i)
{
	return 2 * i;
}

int right(int i)
{
	return 2 * i + 1;
}

void max_heapify(int i, int* head)
{
	int L = left(i);
	int R = right(i);
	int temp;
	int langest;
	
	if (L <= head[0] && head[L] > head[i])
	{
		langest = L;
	}
	else//此处的else很重要
	{
		langest = i;
	}

	if (R <= head[0] && head[R] > head[langest])
	{
		langest = R;
	}
	
	if (langest != i)
	{
		//exchange head[i] with head[langest]
		temp = head[langest];
		head[langest] = head[i];
		head[i] = temp;
		max_heapify(langest, head);
	}
}

//构建最大堆
void  build_max_heap(int* head)
{
	for (int i = head[0] / 2; i > 0; i--)
	{
		max_heapify(i, head);
	}
}

//堆排序
void heap_sort(int* head)
{
	int temp;
	build_max_heap(head);
	for (int i = head[0]; i > 1; i--)
	{
		//exchange head[i] with head[1]
		temp = head[i];
		head[i] = head[1];
		head[1] = temp;
		head[0] = head[0] - 1;
		max_heapify(1, head);
	}
}
