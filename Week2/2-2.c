#include <stdio.h>

int Perfect(int n)
{
	int i;
	int sum = 0;
	for (i = 1; i < n; i++)
		if (n%i == 0)
			sum += i;
	if (sum == n)
		return 1;
	else
		return 0;
}

int main() {
	int n;
	int i;

	for (n = 1; n <= 10000; n++) {
		if (Perfect(n) == 1) {
			printf("%d =", n);
			for (i = 1; i < n; i++) {
				if (n % i == 0) {
					if (i == 1)
						printf("%2d", i);
					else
						printf(" + %2d", i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
