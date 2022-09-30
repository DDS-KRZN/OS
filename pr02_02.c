#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	srand(time(NULL));
	int n, i;
	int lower = -10;
	int upper = 50;
	while(1){
		printf("Enter the number of array elements: ");
		scanf("%d", &n);
		if (n<1)
		{
			printf("Invalid value entered!\a\n");
		} else{
			break;
		}
	}
	int arr[n];
	int sum_arr = 0;
	int average_arr;
	for (i = 0; i < n; ++i)
	{
		arr[i] = (rand() % (upper - lower + 1)) + lower;
		sum_arr += arr[i];
		printf("%d\t", arr[i]);
	}
	printf("\nSum: %d\n", sum_arr);
	average_arr = (sum_arr)/(n);
	printf("\nAverage: %d\n", average_arr);

	int number_greater = 0;
	for (i = 0; i < n; ++i)
	{
		if (arr[i]>average_arr)
		{
			number_greater++;
		}
	}
	printf("The number of elements greater than the average value of the array elements: %d\n", number_greater);
	printf("----------\n");
	int r, signal;
	int r_sum = 0;
	for (i = 0; i < n; ++i)
	{
		if (arr[i]<0)
		{
			r = i;
			signal = 1;
			break;
		}
	}
	if (signal == 1)
	{
		for (i = r+1; i < n; ++i)
		{
			r_sum += arr[i];
		}
		printf("The sum of the modules of the array elements located after the first negative element: %d\n", r_sum);
	} else{
		printf("No negative numbers found!\n\a");
	}
	
	return 0;
}
