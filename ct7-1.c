#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* any_func(void * args){
	int i;
	for (i = 0; i < 10; ++i)
	{
		fprintf(stderr, "Child Thread. Interation: %d\n", i+1);
		sleep(2);
	}
	return NULL;
}

int main(void)
{
	pthread_t thread;
	int result;
	result = pthread_create(&thread, NULL, &any_func, NULL);
	if (result != 0)
	{
		fprintf(stderr, "Error\n");
		return 1;
	}
	int i;
	for (i = 0; i < 10; ++i)
	{
		fprintf(stderr, "Main Thread. Interation: %d\n", i+1);
		sleep(2);
	}
	return 0;
}
