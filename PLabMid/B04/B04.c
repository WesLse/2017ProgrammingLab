#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int min, sec, total, interval = 1;
	int h, m, s, ms = 0;
	clock_t start, now, duration;

	printf("타이머 몇분: ");
	scanf("%d", &min);
	printf("       몇초: ");
	scanf("%d", &sec);

	total = (min * 60 + sec) * 1000;

	start = clock();
	while (interval != 0)
	{
		now = clock();
		duration = now - start;
		interval = total - duration;
		h = interval / 3600000;
		m = interval / 60000 - (60 * h);
		s = interval / 1000 - (3600 * h) - (60 * m);
		ms = interval % 1000;
		printf("\r남은 시간 %d:%02d:%02d.%03d", h, m, s, ms);
	}
	printf("\nTime Out!!\n");
}