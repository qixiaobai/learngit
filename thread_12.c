#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
//
void thread1(char s[])
{
	printf("This is a pthread1.\n");
	printf("%s\n",s);
	pthread_exit((void *)"the first return !");
}
//
void thread2(char s[])
{
	int *a=malloc(sizeof(int));
	*a=466;
	printf("This is a pthread2.\n");
	printf("%s\n",s);
	pthread_exit((void *)a);
}
//
int main(void)
{
	pthread_t id1,id2;
	void *a1, *a2;
	int i,ret1,ret2;
	char s1[]="This is first thread!";
	char s2[]="This is second thread!";
	//
	ret1=pthread_create(&id1,NULL,(void *) thread1,s1);
	if(ret1 != 0)
	{
		printf("Create pthread1 error!\n");
		exit(1);
	}
	//
	//
	ret2=pthread_create(&id2,NULL,(void *) thread2,s2);
	if(ret2 != 0)
	{
		printf("Create pthread2 error!\n");
		exit(1);
	}
	//
	//	
	pthread_join(id1,&a1);
	printf("%s\n",(char *)a1);
	//	
	printf("This is the main process.\n");
	//
	pthread_join(id2,&a2);
	printf("%d\n",*(int*)a2);
	return 0;
}
	
