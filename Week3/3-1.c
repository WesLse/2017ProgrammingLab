#include <stdio.h>
#include <time.h>
int main() {
	char *date[7] = { "일", "월", "화", "수", "목", "금", "토" };
	time_t now;

	time(&now); // 1970년 이후 1초 단위로 증가
	printf("%d\n", now);
	char *ctime(now); // 시간을 문자열로 반환
	printf("ctime() : %s", ctime(&now));
	struct tm *tp = localtime(&now);
	printf("%d년 %d월 %d일 %s요일 %d시 %d분 %d초\n", 1900 + tp->tm_year, tp->tm_mon, tp->tm_mday, date[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);
	return 0;
}