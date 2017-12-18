
#include <stdio.h>
#include <time.h>

int main() {
	time_t now, oldnow = 0; //now는 1970.01.01 0:0:00 = 0 부터 1초씩 증가
	time(&now);
	//printf("now = %d\n", now);

	char *ctime(now);
	//printf("ctime() = %s\n", ctime(&now));

	char *date[7] = { "일", "월", "화", "수", "목", "금", "토" };

	struct tm *tp;
	while (1) {

		time(&now);
		tp = localtime(&now);
		if (oldnow != now) {
			printf("%d년 %d월 %d일 %s요일 %d시 %d분 %d초\r", 1900 + tp->tm_year, tp->tm_mon, tp->tm_mday, date[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);
			oldnow = now;
		}
	}
}