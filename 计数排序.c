#include <stdio.h>
#include <stdlib.h>

void counting_sort(int*, int*, int);

void main()
{
	int origin[7] = { 6,5,2,9,1,5,6 };
	int order[7];
	counting_sort(origin, order, 9);
	for (int i = 1; i <= order[0]; i++)
	{
		printf("%d\t", order[i]);
	}
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
void counting_sort(int* origin, int* order, int max)
{
	int* C = (int*)malloc((max + 1) * sizeof(int));
	for (int i = 0; i <= max; i++)
		C[i] = 0;
	for (int i = 0; i < origin[0]; i++)
		C[origin[i]]++;
	for (int i = 1; i <= max; i++)
		C[i] += C[i - 1];
	for (int i = 1; i <= origin[0]; i++)
	{
		order[C[origin[i]]] = origin[i];
		C[origin[i]]--;
	}
	order[0] = origin[0];
	free(C);
}