#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int res,n;
	char buffer[100];
	res = open("fifo1",O_NONBLOCK,O_RDONLY);
	n = read(res,buffer,100);
	printf("reader process having pid %d started\n",getpid());
	printf("data recieved by reciever %d is: %s\n",getpid(),buffer);
}
