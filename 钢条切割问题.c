#include <stdio.h>
#include <limits.h>

int cut_rod();
int max();

void main()
{
	int price[11] = { 10, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int a = cut_rod(price, 9);
	printf("价格最高为%d\n",a);
}

int cut_rod(int* price, int length)
{
	if (!length)
		return 0;
	int q = INT_MIN;
	for (int i = 1; i <= length; i++)
		q = max(q, price[i] + cut_rod(price, length - i));
	return q;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}