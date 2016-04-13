#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cut_rod();
int memoized_cut_rod();
int MAX();
int memoized_cut_rod_aux();
int bottom_up_cut_rod();

void main()
{
	int price[11] = { 10, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	//int a = cut_rod(price, 9);
	//int a = memoized_cut_rod(price, 10);
	int a = bottom_up_cut_rod(price, 10);
	printf("价格最高为%d\n",a);
}

/*************************************************
Function: MAX(int a, int b)
Description: 返回a,b中较大值
Calls: NULL
Called By: cut_rod(), memoized_cut_rod_aux(), bottom_up_cut_rod()
Input:  int a->参与比较的值
		int b->参与比较的值
Output: NULL
Return: 返回a,b中较大值
Others: NULL
*************************************************/
int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

/*************************************************
Function: cut_rod(int* price, int length)
Description: 利用递归，求长为length的钢条的最高售价
Calls: cut_rod(), MAX()
Called By: main()
Input: iny* price->各长度对应的单价的数组
	   int length->钢条长度
Output: NULL
Return: 返回长为length的钢条的最高售价
Others: 递归
*************************************************/
int cut_rod(int* price, int length)
{
	if (!length)
		return 0;
	int q = INT_MIN;
	for (int i = 1; i <= length; i++)
		q = MAX(q, price[i] + cut_rod(price, length - i));
	return q;
}
/*************************************************
Function: cut_rod(int* price, int length)
Description: 利用递归，求长为length的钢条的最高售价
Calls: cut_rod()
Called By: main()
Input: iny* price->各长度对应的单价的数组
int length->钢条长度
Output: NULL
Return: 返回长为length的钢条的最高售价
Others: 递归
*************************************************/
int memoized_cut_rod(int* price, int length)
{
	int* memory = (int*)malloc((length + 1)*sizeof(int));

	for (int i = 0; i <= length; i++)
		memory[i] = INT_MIN;

	int temp = memoized_cut_rod_aux(price, length, memory);
	free(memory);
	return temp;
}

int memoized_cut_rod_aux(int* price, int length, int* memory)
{
	int temp;

	if (memory[length] != INT_MIN)
		return memory[length];

	if (length == 0)
	{
		temp = 0;
	}
	else
	{
		temp = INT_MIN;

		for (int i = 1; i <= length; i++)
			temp = MAX(temp, price[i] + memoized_cut_rod_aux(price, length - i, memory));
	}

	memory[length] = temp;
	return temp;
}

/*************************************************
Function: bottom_up_cut_rod(int* price, int length)
Description: 求长为length的钢条的最高售价
Calls: MAX()
Called By: main()
Input: iny* price->各长度对应的单价的数组
int length->钢条长度
Output: NULL
Return: 返回长为length的钢条的最高售价
Others: 非递归
*************************************************/
int bottom_up_cut_rod(int* price, int length)
{
	int temp;
	int* memory = (int*)malloc((length + 1)*sizeof(int));
	memory[0] = 0;

	for (int i = 1; i <= length; i++)
	{
		temp = INT_MIN;

		for (int j = 1; j <= i; j++)
		{
			temp = MAX(temp, price[i] + memory[i - j]);
		}

		memory[length] = temp;
	}
	free(memory);
	return temp;
}