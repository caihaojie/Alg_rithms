#include <stdio.h>
#include <stdlib.h>
#define EXIT_FAILURE 1

struct matrix
{
	int columns;
	int rows;
	int(*address)[];
};

typedef struct matrix matrix;

void matrix_chain_order();
matrix matrix_multiply();

void main()
{
	int p[] = { 30,35,15,5,10,20,25 };
	int n = 6;
	int m[6][6] = {0};
	int s[6][6] = {0};
	matrix_chain_order(p, n, m, s);
	
	//printf("%d\t", m[1][3]);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			printf("\t%d",m[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("\t%d", s[i][j]);
		}
		printf("\n");
	}
}

/*************************************************
Function: matrix_multiply(matrix A, matrix B)
Description: 两矩阵相乘
Calls: malloc()
Called By: main()
Input:  matrix A->其中一个矩阵的信息
		matrix B->令一个矩阵的信息
Output: NULL
Return: 相乘得到的矩阵的信息
Others: NULL
*************************************************/
matrix matrix_multiply(matrix A, matrix B)
{
	if (A.columns == B.rows)
	{
		int(*result)[] = (int**)malloc(A.rows * B.columns * sizeof(int));

		for (int i = 0; i < A.rows; i++)
		{
			for (int j = 0; j < B.columns; j++)
			{
				(*result + i)[j] = 0;

				for (int k = 0; k < A.columns; k++)
				{
					(*result + i)[j] += (*A.address + i)[k] * (*B.address + k)[j];
				}
			}
		}
		matrix C;
		C.address = result;
		C.columns = B.columns;
		C.rows = A.rows;
		return C;
	}
	else
	{
		printf("\n两个矩阵不能相乘！！\n");
		exit(EXIT_FAILURE);
	}
}

/*************************************************
Function: matrix_chain_order(int* p, int n, int (*m)[], int (*s)[])
Description: 获得最优解
Calls: NULL
Called By: main()
Input:  int* p->存放矩阵链信息的数组
		int n->数组p的长度，不包括p[0]
		int (*m)[]->存放最优解的二维数组
		int (*s)[]->存放分隔方式的二维数组
Output: NULL
Return: NULL
Others: NULL
*************************************************/
void matrix_chain_order(int* p, int n, int (*m)[], int (*s)[])
{	
	int j,L,i,k;

	for (L = 0; L < n; L++)
	{
		for (i = 0; i < n - L + 1; i++)
		{
			j = i + L - 1;
			(*m + i)[j] = INT_MAX;
			for (k = i; k <=j - 1; k++)
			{
				int	q = (*m + i)[k] + (*m + k + 1)[j] + p[i - 1] * p[k] * p[j];
				if (q < (*m + i)[j])
				{
					(*m + i)[j] = q;
					(*s + i)[j] = k;
				}
			}
		}
	}
}