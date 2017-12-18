#include <stdio.h>
int gcd(int n, int m)
{
	while (n) {
		int t = m%n;
		m = n;
		n = t;
	}
	return m;
}
int lcm(int n, int m)
{
	int g = gcd(n, m);
	return g*(n / g)*(m / g);
}

int henry(int a, int b) {
	
	
	int x;
	
	if (b % a != 0)
		x = b / a + 1;
	else
		x = b / a;

	if (a == 1)
		return x;
	

	if (gcd(x,b) == 1) {
		a = a*x - b;
		a /= gcd(a, lcm(x,b));
		b = lcm(x,b) / gcd(a, lcm(x,b));
		return henry(a, b);
	}
	else {
		a = a *(lcm(x,b) / b) - (lcm(x,b) / x);
		a /= gcd(a, lcm(x, b));
		b = lcm(x,b) / gcd(a, lcm(x, b));
		return henry(a, b);
	}



}

int main() {
	int loop;
	int a, b;
	int i;
	scanf("%d", &loop);

	for (i = 0; i < loop; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", henry(a, b));
	};

	return 0;
}