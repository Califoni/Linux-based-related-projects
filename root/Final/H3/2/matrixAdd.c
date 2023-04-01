#include<stdio.h>
#include<stdlib.h>
int **matrixAdd(int **a,int **b) {

	int row_a = 3;
	int row_b = 3;
	int col_a = 3;
	int col_b = 3;
	int **ans = (int **)malloc(sizeof(int**[3]));

	if (row_a == row_b && col_a == col_b)
	{
		int i, j;
		for (i = 0; i < row_a; i++) {
			ans[i] = (int *)malloc(sizeof(int*[3]));
			for (j = 0; j < col_a; j++) {
				ans[i][j] = a[i][j] + b[i][j];
			}
		}
		return ans;
	}
	else
	{
		printf("矩阵不符合相加的规则\n");
		return NULL;
	}
}
