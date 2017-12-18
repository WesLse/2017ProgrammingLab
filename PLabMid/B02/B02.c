#include <stdio.h>

int trisum1(int n)
{
	int i;
	int sum = 0;
	n = (n / 3) * 3;

	for (i = n; i > 0; i -= 3)
		sum += i;
	return sum;
}

int trisum2(int n)
{
	int sum = 0;
	n = (n / 3) * 3;
	while (n)
	{
		sum += n;
		n -= 3;
	}
	return sum;
}

int trisum3(int n)
{
	int sum = 0;
	n = (n / 3) * 3;

	if (n < 3)
		return 0;
	else
		return n + trisum1(n - 3);
}

int Sum(int n)
{
	if (n < 3)
		return 0;
	else
		return trisum1(n) + Sum(n - 3);
}

void main() {
	int n = 100;
	printf("(1) for trisum1(%d) = %d\n", n, trisum1(n));
	printf("(2) while trisum2(%d) = %d\n", n, trisum2(n));
	printf("(3) Àç±Í trisum3(%d) = %d\n", n, trisum3(n));
	printf("(4) Sum(%d) = %d\n", n, Sum(n));
}