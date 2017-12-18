#include <stdio.h>

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int x = 100, y = 200;
	printf("swap() 호출 전 x = %d y = %d\n", x, y);
	swap(&x, &y);
	printf("swap() 호출 후 x = %d y = %d\n", x, y);
	return 0;
}