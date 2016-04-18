#include <stdio.h>
#include <stdlib.h>

int left();
int right();
void build_max_heap();
void max_heapify();
void heap_sort();

void main()
{
	//为了便于之后操作，第一个元素是数组长度->heap_size
	int target[7] = {6,5,3,4,9,8,1};
	int length = target[0];
	heap_sort(target);
	for (int i = 1; i <= length; i++)
	{
		printf("%d\t", target[i]);
	}
}

//返回i的左子结点位置
int left(int i)
{
	return 2 * i;
}

//返回i的右子结点位置
int right(int i)
{
	return 2 * i + 1;
}

/*************************************************
Function: max_heapify(int i, int* head)
Description: 构造最大树
Calls: left(), right()
Called By: build_max_heap(), heap_sort()
Input:  int* head->数组首地址
		int i->数组中第i个元素（head[0]默认是第0个）
Output: NULL
Return: NULL
Others: 递归
*************************************************/
void max_heapify(int i, int* head)
{
	//i的左子结点值
	int L = left(i);

	//i的右子结点值
	int R = right(i);
	int temp;
	int langest;
	
	//将head[i],head[L],head[R]中最大值的位置赋给langest
	if (L <= head[0] && head[L] > head[i])
	{
		langest = L;
	}
	else
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

		//对交换了值的子树 进行相同操作
		max_heapify(langest, head);
	}
}

//构建最大堆
void  build_max_heap(int* head)
{
	//从下到上构造最大堆
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

	//令head[i]总是数组前head[0]个元素中最大的，将它与第head[0]个元素互换位置，达到从小到大排序的目的
	for (int i = head[0]; i > 1; i--)
	{
		//exchange head[i] with head[1]
		temp = head[i];
		head[i] = head[1];
		head[1] = temp;
		head[0] = head[0] - 1;

		//再次构造最大堆
		max_heapify(1, head);
	}
}
