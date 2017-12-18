#include <stdio.h>

int main() {
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char *date[7] = { "일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일" };
	int test;
	int mon, day, sumday;

	scanf("%d", &test);
	while (test--)
	{
		scanf("%d %d", &mon, &day);
		sumday = 0;
		if (!((mon >= 1) && (mon <= 12)) || !((day >= 1) && (day <= 31)) || (mon == 2 && day > 28))
		{
			printf("N/A\n");
			continue;
		}

		for (int i = 0; i < mon - 1; i++)
			sumday += month[i];
		sumday += (day + 2); //수요일부터 시작
		sumday %= 7;

		printf("%s\n", date[sumday]);
	}
}