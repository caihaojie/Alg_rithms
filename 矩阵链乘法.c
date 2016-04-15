#include <stdio.h>
#include <stdlib.h>
#define EXIT_FAILURE 1

struct matrix
{
	int columns;
	int rows;
	int (*address)[];
};

typedef struct matrix matrix;

matrix matrix_multiply();

void main()
{
	int _A[3][3] = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1}
	};
	int _B[3][3] = {
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	matrix A, B;
	A.address = _A;
	B.address = _B;
	A.columns = A.rows = B.columns = B.rows = 3;
	B.rows = 2;
	matrix C = matrix_multiply(A, B);

	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < B.columns; j++)
		{
			printf("%d\t", (*C.address + i)[j]);
		}
		printf("\n");
	}
}

matrix matrix_multiply(matrix A, matrix B)
{
	if (A.columns == B.rows)
	{
		int (*result)[] = (int**)malloc(A.rows * B.columns * sizeof(int));

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
