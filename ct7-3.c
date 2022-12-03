#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* func_1(void * args){
	int i;
	for (i = 0; i < 10; ++i)
	{
		fprintf(stderr, "Thread. Interation: %d\n", i+1);
		sleep(3);
	}
	return NULL;
}

void* func_2(void * args){
	int i, rand_val;
	while (1)
	{
		rand_val = rand()%10;
		if (rand_val == args)
		{
			printf("Find!\a\n");
			break;
		}
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	srand(time(NULL));
	int value;
	printf("Enter value (0 - 9): ");
	scanf("%d", &value);
	
	pthread_t thread1;
	int result1;
	result1 = pthread_create(&thread1, NULL, &func_1, value);
	if (result1 != 0)
	{
		fprintf(stderr, "Error\n");
		return 1;
	}

	pthread_t thread2;
	int result2;
	result2 = pthread_create(&thread2, NULL, &func_2, value);
	if (result2 != 0)
	{
		fprintf(stderr, "Error\n");
		return 1;
	}
	while(1);
	return 0;
}
