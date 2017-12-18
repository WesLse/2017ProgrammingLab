#include <stdio.h>
#include <math.h>

double factorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
double myexp(int x)
{
	int i = 1;
	double term, sum, oldsum;
	oldsum = 0.0;
	sum = 1.0;
	term = 1.0;
	while (1) {
		term = pow(x, i) / factorial(i);
		oldsum = sum;
		sum += term;
		if ((sum - oldsum) <= 0.0000001)
			break;
		i++;
	}
	return sum;
}
int main() {
	int i;
	printf("  exp() : ");
	for (i = 1; i <= 5; i++)
		printf("%lf ", exp((double)i));
	printf("\n");
	printf("myexp() : ");
	for (i = 1; i <= 5; i++)
		printf("%lf ", myexp(i));
	printf("\n");
	return 0;
}