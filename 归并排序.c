#include <stdio.h>
#include <stdlib.h>

int* MERGE();
int* copyValue();
void MERGE_SORT();
int main()
{
	int target[6] = {6,5,8,12,0,4};
	MERGE_SORT(target,0,5);
	for (int temp = 0; temp < 6; temp++)
	{
		printf("%d\n", *(target + temp));
	}
	return 0;
}     

/*************************************************
Function: MERGE_SORT(int* arr, int p, int r)
Description: 对数组arr[]中从第p个到第r个元素进行排序
Calls: MERGE()
Called By: main()
Input:  int* arr->待排序的数列首地址
		int p->数组arr[]中排序起始位置
		int r->数组arr[]中排序结束位置
Output: NULL
Return: NULL
Others: 需要递归
*************************************************/
void MERGE_SORT(int* arr, int p, int r)
{
	int q = 0;

	if(p < r)
	{
		//将原数组分成两半，分别利用递归进行排序
		q = (p + r) / 2;
		MERGE_SORT(arr, p, q);
		MERGE_SORT(arr, q + 1, r);
		MERGE(arr, p, q, r);
	}
}

/*************************************************
Function: MERGE(int* arr, int p, int q, int r)
Description: 对数组arr[]中从第p个到第r个元素进行排序
Calls: malloc()
Called By: main()
Input:  int* arr->待排序的数组首地址
		int p->数组arr[]中排序起始位置
		int q->数组arr[]中排序分割位置
		int r->数组arr[]中排序结束位置
Output: NULL
Return: arr[]的首地址
Others: 数组arr[]中，第p个到第q个元素及第q+1个到第r个元素分别都是排好序的
*************************************************/
int* MERGE(int* arr, int p, int q, int r)
{
	int n_1 = q - p + 1;
	int n_2 = r - q;
	int i = 0;
	int j = 0;

	//创建数组array_1,array_2保存arr[]中的两段值
	int* array_1 = (int*)malloc((n_1 + 1) * sizeof(int));
	int* array_2 = (int*)malloc((n_2 + 1) * sizeof(int));
	array_1 = copyValue(arr, array_1, n_1, p);
	array_2 = copyValue(arr, array_2, n_2, q + 1);

	//将两个有序数组array_1[],array_2[]中的值按从小到大顺序排列
	for (int temp = p; temp <= r; temp++)
	{
		if (array_1[i] > array_2[j])
		{
			arr[temp] = array_2[j];
			j++;
		}
		else
		{
			arr[temp] = array_1[i];
			i++;
		}
	}
	free(array_1);
	free(array_2);
	return arr;
}

/*************************************************
Function: copyValue(int* arr, int* newArr, int length, int start)
Description: 将arr[]数组从start开始复制length长度个值到数组newArr[]中
Calls: NULL
Called By: MERGE()
Input:  int* arr->源数组首地址
		int* newArr->被赋值的数组的首地址
		int length->arr[]中要被复制的长度
		int start->arr[]中复制的起始位置
Output: NULL
Return: 复制的结果int* newArr
Others: NULL
*************************************************/
int* copyValue(int* arr, int* newArr, int length, int start)
{
	for (int temp = 0; temp < length; temp++)
	{
		*(newArr + temp) = arr[start + temp];
	}
	*(newArr + length) = INT_MAX;
	return newArr;
}