#include <stdio.h>

int main()
{
	int sum = 100;
	int n;
	while (1) {
		printf("sum = %d  ", sum);
		if (sum == 0)
			break;
		printf("�� �� �Է� : ");
		scanf("%d", &n);
		sum -= n;
	}
	return 0;
}