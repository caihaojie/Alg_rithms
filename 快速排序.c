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

void exchange(int* head, int a, int b)
{
	int temp = head[a];
	head[a] = head[b];
	head[b] = temp;
}

int partition(int* head, int p, int r)
{
	int x = head[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (head[j] <= head[r])
		{
			i++;
			if (i != j)//比书上的代码多了一个判断
				exchange(head, i, j);
		}
	}
	exchange(head, i + 1, r);
	return i + 1;
}

void quick_sort(int* head, int p, int r)
{
	if (p < r)
	{
		int q = partition(head, p, r);
		quick_sort(head, p, q - 1);
		quick_sort(head, q + 1, r);
	}
}
