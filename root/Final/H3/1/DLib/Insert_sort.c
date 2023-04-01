#include<stdio.h>

void Insert_sort(int *a,int len){

       	int i,j;
       	for(i=2;i<len;i++)
    	{
        //如果这个数比前一个数小，就要交换
        if(a[i]<a[i-1])
        {
            //把小的数存放再a[0]位置，作为哨兵
            a[0]=a[i];
            //将前面比这个数大的数后移
            for(j=i-1;a[0]<a[j];j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=a[0];
        }
    }
}
