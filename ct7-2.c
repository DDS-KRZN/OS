#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct thread_arg
{
	char * str;
	int num;
};

void * func_1(void * arg){
	struct thread_arg targ = *(struct thread_arg *) arg;
	fprintf(stderr, "str=%s\n", targ.str);
	fprintf(stderr, "num=%d\n", targ.num);
	int i;
	for (i = 0; i < targ.num; ++i)
	{
		fprintf(stderr, "%s. Interation: %d\n", targ.str, i+1);
		sleep(2);
	}
	return NULL;
}

void * func_2(void * arg){
	struct thread_arg targ = *(struct thread_arg *) arg;
	fprintf(stderr, "str=%s\n", targ.str);
	fprintf(stderr, "num=%d\n", targ.num);
	int i;
	for (i = 0; i < targ.num; ++i)
	{
		fprintf(stderr, "%s. Interation: %d\n", targ.str, i+1);
		sleep(2);
	}
	return NULL;
}

void * func_3(void * arg){
	struct thread_arg targ = *(struct thread_arg *) arg;
	fprintf(stderr, "str=%s\n", targ.str);
	fprintf(stderr, "num=%d\n", targ.num);
	int i;
	for (i = 0; i < targ.num; ++i)
	{
		fprintf(stderr, "%s. Interation: %d\n", targ.str, i+1);
		sleep(2);
	}
	return NULL;
}

void * func_4(void * arg){
	struct thread_arg targ = *(struct thread_arg *) arg;
	fprintf(stderr, "str=%s\n", targ.str);
	fprintf(stderr, "num=%d\n", targ.num);
	int i;
	for (i = 0; i < targ.num; ++i)
	{
		fprintf(stderr, "%s. Interation: %d\n", targ.str, i+1);
		sleep(2);
	}
	return NULL;
}


int main(void)
{
	pthread_t thread1;
	int result1;
	struct thread_arg targ1;
	targ1.str = "Thread 1";
	targ1.num = 10;
	result1 = pthread_create(&thread1, NULL, &func_1, &targ1);
	if (result1 != 0)
	{
		fprintf(stderr, "Error\n");
		return 1;
	}

	pthread_t thread2;
	int result2;
	struct thread_arg targ2;
	targ2.str = "Thread 2";
	targ2.num = 5;
	result2 = pthread_create(&thread2, NULL, &func_2, &targ2);
	if (result2 != 0)
	{
		fprintf(stderr, "Error\n");
		return 1;
	}

	pthread_t thread3;
	int result3;
	struct thread_arg targ3;
	targ3.str = "Thread 3";
	targ3.num = 3;
	result3 = pthread_create(&thread3, NULL, &func_3, &targ3);
	if (result3 != 0)
	{
		fprintf(stderr, "Error\n");
		return 1;
	}

	pthread_t thread4;
	int result4;
	struct thread_arg targ4;
	targ4.str = "Thread 4";
	targ4.num = 7;
	result4 = pthread_create(&thread4, NULL, &func_4, &targ4);
	if (result4 != 0)
	{
		fprintf(stderr, "Error\n");
		return 1;
	}
	while(1);
	return 0;
}
