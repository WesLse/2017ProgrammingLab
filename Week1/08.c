#include <stdio.h>

void print_array(int arr[], int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

double compute_avg(int arr[], int n)
{
	int i, sum =0;
	double avg;
	for (i = 0; i < n; i++)
		sum += arr[i];
	avg = sum / n;

	return avg;
}
int find_max(int arr[], int n)
{
	int i;
	int temp = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] > temp)
			temp = arr[i];
	}
	return temp;
}
int find_min(int arr[], int n)
{
	int i;
	int temp = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] < temp)
			temp = arr[i];
	}
	return temp;
}
int main()
{
	int arr[10] = { 10, 30, 5, 20, 44, 3, 100, 88, 9, 101 };

	print_array(arr, 10);
	printf("평균 = %lf\n", compute_avg(arr, 10));
	printf("최대 = %d\n", find_max(arr, 10));
	printf("최소 = %d\n", find_min(arr, 10));
	
	return 0;
}