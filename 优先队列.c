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

int heap_maxinum(int* head)
{
	return head[1];
}

int heap_extract_max(int* head)
{
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

void max_heapify(int *head, int i)
{
	int L = i * 2;
	int R = i * 2 + 1;
	int largest;
	if (L < head[0] && head[L] > head[i])
	{
		largest = L;
	}
	else {
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

void build_max_heap(int* head)
{
	for (int i = head[0]/2; i > 0; i--)
	{
		max_heapify(head, i);
	}
}

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
