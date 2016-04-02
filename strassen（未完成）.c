#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

void add2matrix();
void subtract2matrix();
void show_matrix();
void strassen();

void main()
{
	int A[SIZE][SIZE] = {
		{5, 1},
		{2, 3}
	};
	int B[SIZE][SIZE] = {
		{3, 4},
		{6, 9}
	};
	int C[SIZE][SIZE];
	subtract2matrix(A, B, C);
	show_matrix(C);

}

void add2matrix(int(*A)[SIZE], int(*B)[SIZE], int(*C)[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void subtract2matrix(int (*A)[], int (*B)[], int(*C)[])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void show_matrix(int (*A)[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}
}

void strassen(int N, int (*A)[], int (*B)[], int (*C)[])
{
	
	for (int i = 0; i < N/2; i++)
	{
		for (int j = 0; j < N/2; j++)
		{
			;
		}
	}
}
