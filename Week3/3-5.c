#include <stdio.h>
#include <time.h>
#include <conio.h>

int main() {
	clock_t start, now, duration;
	int h, m, s, ms = 0;
	printf("Enter로 시작 CTRL-C 누르면 종료\n");
	start = clock();
	while (1) {
		if (kbhit())
			break;
		now = clock();
		duration = now - start;
		h = duration / 3600000;
		m = duration / 60000;
		s = duration / 1000;
		ms = duration % 1000;
		printf("%d:%02d:%02d.%03d\r", h, m, s, ms);
	}
	printf("\n");
}
