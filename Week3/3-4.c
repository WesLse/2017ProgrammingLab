#include <stdio.h>
#include <time.h>
int main() {
	time_t now;
	clock_t start, finish;
	int i, j, k = 0;
	time(&now);
	char *ctime(now);

	printf("시작 : %s", ctime(&now));
	start = clock();
	for (i = 1; i < 100000; i++)
		for (j = 1; j < 100000; j++)
			k++;
	finish = clock();
	time(&now);
	printf("종료 : %s",ctime(&now));
	printf("실행시간 : %f 초입니다.\n\n", (double)(finish -start) /CLOCKS_PER_SEC);
	

	struct tm *tp = localtime(&now);

	printf("시작 : %d:%02d:%02d\n",tp->tm_hour,tp->tm_min,tp->tm_sec);
	start = clock();
	for (i = 1; i < 100000; i++)
		for (j = 1; j < 100000; j++)
			k++;
	finish = clock();
	time(&now);
	tp = localtime(&now);
	printf("종료 : %d:%02d:%02d\n",tp->tm_hour,tp->tm_min,tp->tm_sec); 
	printf("실행시간 : %f 초입니다.\n", (double)(finish - start) / CLOCKS_PER_SEC);
}