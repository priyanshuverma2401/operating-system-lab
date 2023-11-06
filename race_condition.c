#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *fuc1();
void *fuc2();

int shared = 1;		// shared variable

int main()
{
	pthread_t thread1,thread2; //declaring thread variable
	pthread_create(&thread1,NULL,fuc1,NULL);	// creating  first thread
	pthread_create(&thread2,NULL,fuc2,NULL);	// creating second thread
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("the final value of shared variable is: %d\n",shared);	//prints the last updated value of shared variable
}

void *fuc1()
{
	int x;
	x = shared;
	printf("Thread1 reads the value of shared variable as %d\n",x);
	x++;
	printf("local updation by thread 1\n");
	sleep(1);
	shared = x;
	printf("value of shared variable updated by thread 1 is:%d\n",shared);
}

void *fuc2()
{
	int y=shared;
	printf("thread 2 reads the value of shared as %d\n",y);
	y--;
	sleep(1);
	shared =y;
	printf("value of shared variable updated by thread2 is %d\n",shared);
}
