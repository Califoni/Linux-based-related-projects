#include<stdio.h>
void Select_sort(int *p,int n){
    int i,j;
    int min = 0;
    for(i = 0;i < n - 1;i++)//排序次数
    {
        min = i;
        for(j = i + 1;j < n;j++)
        {
            if(p[j] < p[min])
            {
                min = j;//记录交换的元素下标值
            }
        }
        if(i != min)
        {
            int temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }  
    }
}
