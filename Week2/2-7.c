#include <stdio.h>

int main() {

	int test;
	int H, W, N;
	int i;
	int x, y;

	scanf("%d", &test);

	for (i = 0; i < test; i++) {

		scanf("%d %d %d", &H, &W, &N);

		int count = N;
		int last_x = 0, last_y = 0;

		for (x = 1; x <= W; x++) {

			for (y = 1; y <= H; y++) {

				N--;

				if (N == 0) {
					last_x = x;
					last_y = y;
				}
			}
		}

		if (last_x < 10)
			printf("%d0%d\n", last_y, last_x);

		else
			printf("%d%d\n", last_y, last_x);
	}
	return 0;
}