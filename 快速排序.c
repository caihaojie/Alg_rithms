#include <stdio.h>

void exchange(int*, int, int);
int partition(int*, int, int);
void quick_sort(int*, int, int);

void main() 
{
	int target[6] = { 10,4,2,6,8,3 };
	printf("原数列\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", target[i]);
	}
	quick_sort(target, 0, 5);
	printf("\n排序后:\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t",target[i]);
	}
}

//交换head[a]与head[b]的值
void exchange(int* head, int a, int b)
{
	int temp = head[a];
	head[a] = head[b];
	head[b] = temp;
}

/*************************************************
Function: partition(int* head, int p, int r)
Description: 将head[]数组p~r这一段分成两部分，前一段均小于等于head[r],后一段大于head[r]
Calls: exchange()
Called By: quick_sort()
Input:  int* head->数组首地址
		int p->分段开始位置
		int r->分段结束位置
Output: NULL
Return: 第一段的最后一个元素的位置
Others:
*************************************************/
int partition(int* head, int p, int r)
{
	int x = head[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (head[j] <= x)
		{
			i++;
			exchange(head, i, j);
		}
	}
	exchange(head, i + 1, r);
	return i + 1;
}

//利用递归将整段数组很多小段分别进行排序
void quick_sort(int* head, int p, int r)
{
	if (p < r)
	{
		int q = partition(head, p, r);
		quick_sort(head, p, q - 1);
		quick_sort(head, q + 1, r);
	}
}
