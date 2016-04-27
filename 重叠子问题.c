#include <stdio.h>

int** recursive_matrix_chain();

void main()
{
	;
}

int** recursive_matrix_chain(int* p, int i, int j)
{
	if (i == j)
	{
		return NULL;
	}

	int m[i][j];

	//为二维数组m赋初值INT_MAX
	for (int x = 0; x < i; ++x)
	{
		for (int y = 0; y < j; ++y)
		{
			m[x][y] = INT_MAX;
		}
	}

	for (int k = i; k < j; ++k)
	{
		int q = recursive_matrix_chain(p, i, k) + recursive_matrix_chain(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		if (q < m[i][j])
		{
			m[i][j] = q;
		}
	}
	reutrn m[i][j];
}