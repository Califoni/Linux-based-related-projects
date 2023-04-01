#include<stdio.h>
#include "matrix.h"
#include<stdlib.h>
int main() {
	int **a = (int **)malloc(sizeof(int**[3]));
	int **b= (int **)malloc(sizeof(int**[3]));
	int i, j;
	for (i = 0; i < 3; i++) {
		a[i] = (int *)malloc(sizeof(int*[3]));

		b[i] = (int *)malloc(sizeof(int*[3]));
		for (j = 0; j < 3; j++) 
			{
				a[i][j] = j - 2*i ;
				b[i][j] = i - 2*j;

			}
	}
	printf("原矩阵a:\n");	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("原矩阵b:\n");	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}

	int row_a = 3;
	int row_b = 3;
	int col_a = 3;
	int col_b = 3;

	int **c;
	c=matrixAdd(a, b);
	printf("相加结果矩阵:\n");
	for (i = 0; i < row_a; i++) {
		for (j = 0; j < col_a; j++)
			printf("%d\t", c[i][j]);
		printf("\n");
	}
	return 0;
}


