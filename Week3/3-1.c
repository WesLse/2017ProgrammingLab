#include <stdio.h>
#include <time.h>
int main() {
	char *date[7] = { "��", "��", "ȭ", "��", "��", "��", "��" };
	time_t now;

	time(&now); // 1970�� ���� 1�� ������ ����
	printf("%d\n", now);
	char *ctime(now); // �ð��� ���ڿ��� ��ȯ
	printf("ctime() : %s", ctime(&now));
	struct tm *tp = localtime(&now);
	printf("%d�� %d�� %d�� %s���� %d�� %d�� %d��\n", 1900 + tp->tm_year, tp->tm_mon, tp->tm_mday, date[tp->tm_wday], tp->tm_hour, tp->tm_min, tp->tm_sec);
	return 0;
}