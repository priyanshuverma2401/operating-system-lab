#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *args);
int i,j;
int main()
{
	pthread_t a_thread; //thread declaration
	pthread_create(&a_thread,NULL,thread_function,NULL); //thread is created
	pthread_join(a_thread,NULL); //process wait for thread to finish,comment this line to see diffrence
	printf("inside main programme\n");
	for(j=20;j<25;j++){
		printf("%d\n",j);
		sleep(1);
	}
}

void *thread_function(void *args) //the work t be done by the thread is defined in this function
{
	printf("inside the thread\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}

/* note:  to compile any programmewhich involves the creation of thread(S) use pthread library (lpthread) suppose the above programme is named "thread.c", then to cmpile write $ gcc thread.c -lpthread
*/
