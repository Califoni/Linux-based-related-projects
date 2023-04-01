#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#define LEN 1024
int main()
{
	pid_t child;
	int i,fd_log;
	char cmd[]="mail";
	char buf[LEN];
	char s[]="No mail for root\n";
	memset(buf,'\0',LEN);
	FILE *ptr;
	//创建子进程
	child=fork();
	if(child>0){
		//父进程退出
		exit(0);
	}
	else if(child<0){
		perror("创建子进程失败");
		exit(1);
	}
	//子进程创建新会话
	setsid();
	//将当前目录改成根目录
	chdir("/");
	//重设文件权限掩码
	umask(0);
	//关闭不需要的文件描述符
	for(i=0;i<getdtablesize();i++){
		close(i);
	}

	while(1){
		if(fd_log=open("/root/Final/H6/3/testMail.log",O_CREAT|O_WRONLY|O_APPEND,0600)<0)
		{
			exit(1);
		}
		if((ptr=popen(cmd,"r"))!=NULL)
			while(fgets(buf,100,ptr)!=NULL){
				if(strcmp(buf,s)==0)
					write(fd_log,buf,strlen(buf));
				else{
					write(fd_log,buf,strlen(buf));
				}
			}
		close(fd_log);
		sleep(10);
	}
	exit(0);

}
