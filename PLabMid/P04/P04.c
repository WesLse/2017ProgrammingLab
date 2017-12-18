#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int min, total, interval = 1;
	int h, m, s;
	int midh, midm, mids;
	clock_t start, now, duration;

	printf("알람설정(몇분후 알람) : ");
	scanf("%d", &min);

	total = min * 60 * 1000;

	start = clock();
	while (interval != 0)
	{
		now = clock();
		duration = now - start;
		interval = total - duration;
		midh = duration / 3600000;
		midm = duration / 60000 - (60 * midh);
		mids = duration / 1000 - (3600 * midh) - (60 * midm);
		h = interval / 3600000;
		m = interval / 60000 - (60 * h);
		s = interval / 1000 - (3600 * h) - (60 * m);
		printf("\r경과시간 %02d:%02d:%02d 남은 시간 %02d:%02d:%02d", midh , midm, mids, h, m, s);
	}
	printf("\n!!! 알람 !!!\n");
}