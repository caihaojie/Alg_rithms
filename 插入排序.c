#include <stdio.h>

void quick_sort();

int main()
{
	int tar[6] = { 5,4,6,7,9,0 };
	quick_sort(tar);

	//show the result
	for (int i = 1; i < 6; i++)
	{
		printf("%d\n", tar[i]);
	}
	return 0;
}

/*************************************************
Function: quick_sort(int* head)
Description: 对数组元素进行排序
Calls: NULL
Called By: main()
Input:  int* head->数组首地址
Output: NULL
Return: NULL
Others: head[0] = head.size,head[0]不会参与排序
*************************************************/
void quick_sort(int* head)
{
	int key, i;

	for (int j = 1; j <= head[0]; j++)
	{
		key = head[j];
		i = j - 1;

		while (i >= 1 && key<head[i])
		{
			head[i + 1] = head[i];
			head[i] = key;
			i--;
		}
	}
}