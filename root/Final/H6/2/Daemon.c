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
int main()
{
	pid_t child;
	int i,fd_txt,fd_log;
	//用于随机选取ip
	int choice;
	char buf[]="172.28.228.123";
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
		if(fd_txt=open("/root/Final/H6/2/ip.txt",O_RDONLY|O_APPEND,0600)<0)
		{
			exit(1);
		}
		srand((unsigned)time(NULL));
		//5行ip地址随机选取1行
		choice=rand()%5;
		lseek(fd_txt,choice*sizeof(buf),SEEK_SET);
		read(fd_txt,buf,sizeof(buf));
		close(fd_txt);
		//char *cmd=(char*)malloc(sizeof(char*[30]));
		//strcpy(cmd,"ifconfig eth0 ");
		//strcat(cmd,buf);
		//system(cmd);
		if(fd_log=open("/root/Final/H6/2/ip.log",O_WRONLY|O_APPEND,0600)<0)
		{
			exit(1);
		}
		write(fd_log,buf,strlen(buf));
		close(fd_log);
		sleep(5);
	}
	exit(0);

}
