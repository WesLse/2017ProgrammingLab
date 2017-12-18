#include <stdio.h>

int quadsum1(int n)
{
	int i;
	int sum = 0;
	n = (n / 4) * 4;

	for (i = n; i > 0; i -= 4)
		sum += i;
	return sum;
}

int quadsum2(int n)
{
	int i;
	int sum = 0;
	n = (n / 4) * 4;
	while (n)
	{
		sum += n;
		n -= 4;
	}
	return sum;
}

int quadsum3(int n)
{
	int i;
	int sum = 0;
	n = (n / 4) * 4;

	if (n < 4)
		return 0;
	else
		return n + quadsum3(n - 4);
}

int Sum(int n)
{
	if (n < 4)
		return 0;
	else
		return quadsum1(n) + Sum(n - 4);
}

void main() {
	int n = 100;
	int i;
	int SUM;
	printf("(1) for quadsum1(%d) = %d\n", n, quadsum1(n));
	printf("(2) while quadsum2(%d) = %d\n", n, quadsum2(n));
	printf("(3) Àç±Í quadsum3(%d) = %d\n", n, quadsum3(n));
	SUM = Sum(n);
	printf("(4) SUM = %d\n", SUM);
}