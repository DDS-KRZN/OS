#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	srand(time(NULL));
	int i, n;
	while(1){
		printf("Enter the number of array elements (min: 5): ");
		scanf("%d", &n);
		if (n<5)
		{
			printf("Invalid value entered!\a\n");
		} else{
			break;
		}
	}
	int arr[n];
	int min = 999;
	int min_index;
	for (i = 0; i < n; ++i)
	{
		arr[i] = rand()%100;
		printf("%d\t", arr[i]);
		if (arr[i]<min)
		{
			min = arr[i];
			min_index = i;
		}
	}

	int active_n = n;
	while(1){
		min = 999;
		for (i = 0; i < n; ++i)
		{
			if (arr[i]<min && arr[i]!=NULL)
			{
				min = arr[i];
				min_index = i;
			}
		}
		if (active_n==1)
		{
			break;
		}

		if (min_index==0) // esli arr[0] -- pervaya
		{
			arr[min_index+1] += arr[min_index];
			arr[min_index] = NULL;
		} else if (min_index==(n-1)) // esli arr[n-1] -- poslednyaa
		{
			arr[min_index-1] += arr[min_index];
			arr[min_index] = NULL;
		} else if (arr[min_index-1]==NULL || arr[min_index+1]==NULL){
				int count;
				while(1){
					count++;
					if (arr[min_index-count]!=NULL)
					{
						arr[min_index-count] += arr[min_index];
						arr[min_index] = NULL;
						break;
					} else if (arr[min_index+count]!=NULL)
					{
						arr[min_index+count] += arr[min_index];
						arr[min_index] = NULL;
						break;
					}
				}
			} else{
			int left = arr[min_index-1];
			int right = arr[min_index+1];
			if (left<right)
			{
				arr[min_index-1] += arr[min_index];
				arr[min_index] = NULL;
			} else{
				arr[min_index+1] += arr[min_index];
				arr[min_index] = NULL;
			}
		}
		active_n--;
	}
	printf("\nRemaining point: %d\nIndex: [%d]\n", arr[min_index], min_index);
	return 0;
}
