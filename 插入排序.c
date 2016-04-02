#include <stdio.h>

int main()
{
	int tar[6] = {5,4,6,7,9,0};
	int i = 0, j = 0, key = 0;
	for (j = 1; j <= 5; j++)
	{
		key = tar[j];
		i = j - 1;
		while (i >=0  && key<tar[i])
		{
			tar[i + 1] = tar[i];
			tar[i] = key;
			i--;
		}
	}
	for (i = 0; i < 6; i++)
		printf("%d\n",tar[i]);
	return 0;
}