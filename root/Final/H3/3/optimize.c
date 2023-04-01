#include<stdio.h>

int main(){
	long long i;
	long long sum,a;
	sum=0;
	a=0;

	for(i=0;i<800000000;i++){
		sum+=a;
		a+=1;	
	}
	return 0;
}
