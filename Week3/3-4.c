#include <stdio.h>
#include <time.h>
int main() {
	time_t now;
	clock_t start, finish;
	int i, j, k = 0;
	time(&now);
	char *ctime(now);

	printf("���� : %s", ctime(&now));
	start = clock();
	for (i = 1; i < 100000; i++)
		for (j = 1; j < 100000; j++)
			k++;
	finish = clock();
	time(&now);
	printf("���� : %s",ctime(&now));
	printf("����ð� : %f ���Դϴ�.\n\n", (double)(finish -start) /CLOCKS_PER_SEC);
	

	struct tm *tp = localtime(&now);

	printf("���� : %d:%02d:%02d\n",tp->tm_hour,tp->tm_min,tp->tm_sec);
	start = clock();
	for (i = 1; i < 100000; i++)
		for (j = 1; j < 100000; j++)
			k++;
	finish = clock();
	time(&now);
	tp = localtime(&now);
	printf("���� : %d:%02d:%02d\n",tp->tm_hour,tp->tm_min,tp->tm_sec); 
	printf("����ð� : %f ���Դϴ�.\n", (double)(finish - start) / CLOCKS_PER_SEC);
}