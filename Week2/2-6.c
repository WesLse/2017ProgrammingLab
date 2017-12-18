#include <stdio.h>
#include <stdlib.h>

int main() {

	int *arr;
	int test_set;
	int test_case;
	scanf("%d", &test_set);

	int i;
	int j=0;

	int max;
	int min;

	while (j<test_set) {
		int sum = 0;
		scanf("%d", &test_case);

		arr = (int *)malloc(test_case * sizeof(int));

		for (i = 0; i < test_case; i++)
			scanf("%d", &arr[i]);

		max = arr[0];
		min = arr[0];

		for (i = 0; i < test_case; i++) {

			sum += arr[i];

			if (max < arr[i])
				max = arr[i];
			if (min > arr[i])
				min = arr[i];

		}

		printf("%d %d %d\n", sum, max, min);

		j++;
		
		free(arr);
	}

	

	return 0;

}