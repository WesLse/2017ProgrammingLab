
#include <stdio.h>
#include <time.h>

int main() {
	time_t now, oldnow = 0; //now�� 1970.01.01 0:0:00 = 0 ���� 1�ʾ� ����
	time(&now);
	//printf("now = %d\n", now);

	char *ctime(now);
	//printf("ctime() = %s\n", ctime(&now));

	char *date[7] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	struct tm *tp;
	while (1) {

		time(&now);
		tp = localtime(&now);
		if (oldnow != now) {
			printf("%d�� %d�� %d�� %s���� %d�� %d�� %d��\r", 1900 + tp->tm_year, tp->tm_mon, tp->tm_mday, date[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);
			oldnow = now;
		}
	}
}