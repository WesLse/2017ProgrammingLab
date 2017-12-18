#include <stdio.h>

int main() {
	int i, n_test, x, y;
	scanf("%d", &n_test);
	for (i = 0; i<n_test; i++) {
		scanf("%d %d", &x, &y);
		printf("%d %d\n",x+y, x*y);
	}
	return 0;
}