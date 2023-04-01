#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	//测试总次数n
	int n = 5;
	//测试总耗时
	double sumTime = 0;
	struct timespec t1,t2;

	int i;
	for (i = 0; i < n; i++) {
		srand((unsigned int)time(NULL));
		int num = rand() % 10;
		printf("请输入屏幕上的数字：%d\n", num);
		clock_gettime(CLOCK_MONOTONIC,&t1);
		int input;
		scanf("%d", &input);
		clock_gettime(CLOCK_MONOTONIC,&t2);
		//获取单次运行秒数
		double duration = t2.tv_sec-t1.tv_sec;
		sumTime += duration;
	}

	//测试平均用时
	double avgTime = sumTime / n;
	printf("平均耗时%.2lf秒\n", avgTime);
	return 0;
}

