#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	printf("before fork \n");
	pid = fork();
	if(pid==0)  //executed by child process only
	{
		pid_t pid2;
		pid2 = fork();
		if(pid2==0)
		{
			printf("i'm a grand child having pid: %d\n",getpid());
			printf("my parents(2nd)  pid is: %d\n",getppid());
		}
		else
		{
			printf("i'm a child process having pid: %d\n ",getpid());
			printf("my parents pid is: %d\n",getppid());
		}
	}
	else //executed by parent process only
	{
		printf("i'm a parent process having pid: %d\n",getpid());
		printf("my child pid is: %d\n",pid);
	}
}
