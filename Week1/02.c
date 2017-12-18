#include <stdio.h>

int oddsum1(n);
int oddsum2(n);
int oddsum3(n);

int main()
{
	int i = 0;
	int n = 100;
	int SUM = 0;
	printf("(1) for oddsum1(%d) = %d\n", n, oddsum1(n));
	printf("(2) while oddsum2(%d) = %d\n", n, oddsum2(n));
	printf("(3) Àç±Í oddsum3(%d) = %d\n", n, oddsum3(n));
	
	while (i < n + 1) {
		SUM += oddsum1(i);
		i = i + 2;
	}
	printf("(4) SUM = %d\n", SUM);
}

int oddsum1(n)
{
	int i;
	int sum1 = 0;

	for (i = 1; i <= n; i = i + 2)
	{
		sum1 += i;
	}

	return sum1;
}

int oddsum2(n)
{
	int i = 1;
	int sum2 = 0;

	while (i < n)
	{
		sum2 += i;
		i = i + 2;
	}

	return sum2;
}

int oddsum3(n)
{
	/*
	½º½º·Î Â«
	if (n < 1)
		return 0;
	else {
		if (n % 2 == 0)
			return oddsum3(n - 1);
		else if (n % 2 == 1)
			return oddsum3(n - 2) + n;
	}*/
	if (n <= 1)
		return n;
	if ((n % 2) == 0)
		n = n - 1;
	return n + oddsum3(n - 2);
}