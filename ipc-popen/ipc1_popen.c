//producer process

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
	FILE *rd;
	char buffer[50];
	char input[50];
	char getcammand[50];
	
	printf("enter literals:");
	scanf("%[^\n]s",input);
	

	sprintf(buffer,input);
	rd=popen("wc -c","w");
	fwrite(buffer,sizeof(char),strlen(buffer),rd);
	pclose(rd);
}
