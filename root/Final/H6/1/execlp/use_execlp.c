#include<stdio.h>
#include<unistd.h>

int main(int argc,char **argv){
	if(execlp("ls","ls","-l",NULL)==-1){
		printf("execlp failed\n");
		perror("error");
	}
	return 0;
}
