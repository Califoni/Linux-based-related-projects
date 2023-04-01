#include<stdio.h>
#include<unistd.h>

int main(){
	//构造指向各参数的指针数组
	//再将该数组的地址作为execvp函数参数
	char *argv[]={"find","test.txt",NULL};
	if(execvp("find",argv)==-1){
		printf("execvp failed\n");
		perror("error");
	}
	return 0;	
}
