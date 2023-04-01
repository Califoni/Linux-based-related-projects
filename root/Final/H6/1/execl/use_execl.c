#include<stdio.h>
#include<unistd.h>

int main(int argc,char **argv){
	if(execl("./printRoot",argv[1],NULL)==-1){
		printf("execl failed\n");
		perror("error");
	}
	return 0;
}
