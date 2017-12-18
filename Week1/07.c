#include <stdio.h>

int main() {
	int x;
	int y = 0;
	int z = 0;
	int i = 1;
	int temp;

	printf("정수 x 입력 : "); scanf("%d", &x);
	temp = x;

	do
	{	
		y += temp % 10;

		if ((temp / 10 == 0))
		{
			y += temp / 10;
			break;
		}

		y *= 10;

		temp /= 10;
		
	} while (1);
	z = y * 2;

	printf("뒤집은 수 y = %d 그 수의 2배 수 z = %d", y, z);

	return 0;
}