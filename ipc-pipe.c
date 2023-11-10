#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int fd[2],n;
	char buffer[100];
	pid_t pid;
	pipe(fd);
	pid = fork();
	if(pid > 0) //parent
	{
		printf("passing value to child\n");
		write(fd[1],"hello\n",6);
	}
	else if(pid==0) //child
	{
		printf("child process recieves data\n");
		n = read(fd[0],buffer,100);
		write(1,buffer,n);
	}
	else printf("error\n");
}
