#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int res,n;
	res = open("fifo1",O_NONBLOCK,O_WRONLY);
	write(res,"new data",8);
	printf("sender process having pid %d has sent the data\n",getpid());
}
