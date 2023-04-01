#include "libsort.h"
#include<stdio.h>
int main(){
	int arr[10] = {9,5,1,3,8,4,6,7,0,2};
	Bubble_sort(arr,10);
	int i;
	printf("冒泡排序：");
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");	

	int arr1[10]={9,5,1,3,8,9,6,5,0,2};
	Select_sort(arr1,10);
	printf("选择排序：");
        for(i=0;i<10;i++)
                printf("%d ",arr1[i]);

	printf("\n");
	//插入排序的第0号位元素不参与排序，属于哨兵位置
	int arr2[11]={0,8,6,9,7,2,3,1,5,2,1};
	Insert_sort(arr2,11);
	printf("插入排序：");
        for(i=1;i<11;i++)
                printf("%d ",arr2[i]);
        printf("\n");
	return 0;
}
