#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

void *thread_function(void *arg);
int num[2] = {3,5};
int main()
{
	pthread_t a_thread; //thread declaration
	void *result;
	pthread_create(&a_thread,NULL,thread_function,(void*)num); //thread is created
	pthread_join(a_thread,&result); //process wai to finish the thread comment this line to see the difference
	printf("inside main function");
	printf("\nOthread returned: %s\n",(char *)result);
}

void *thread_function(void *args)
{
	printf("inside thread");
	int *x = args;
	int sum = x[0] + x[1];
	printf("\nsum is: %d\n",sum);
	pthread_exit("sum calculated");
}

