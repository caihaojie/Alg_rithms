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

void MERGE_SORT(int* arr, int p, int r)
{
	int q = 0;
	if(p < r)
	{
		q = (p + r) / 2;
		MERGE_SORT(arr, p, q);
		MERGE_SORT(arr, q + 1, r);
		MERGE(arr, p, q, r);
	}
}

int* MERGE(int* arr,int p,int q,int r)
{
	int n_1 = q - p + 1;
	int n_2 = r - q;
	int i = 0;
	int j = 0;
	int* array_1 = (int*)malloc((n_1 + 1) * sizeof(int));
	int* array_2 = (int*)malloc((n_2 + 1) * sizeof(int));
	array_1 = copyValue(arr, array_1, n_1, p);
	array_2 = copyValue(arr, array_2, n_2, q + 1);
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

int* copyValue(int* arr, int* newArr, int length, int start)
{
	for (int temp = 0; temp < length; temp++)
	{
		*(newArr + temp) = arr[start + temp];
	}
	*(newArr + length) = _CRT_INT_MAX;
	return newArr;
}