#include <stdio.h>

int main()
{
	int startday, i, month;
	int m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("��� ���� �Է� : ");
	scanf("%d", &month);
	startday = 1;
	for (i = 0; i < month - 1; i++)
		startday += m[i];
	startday %= 7;
	printf("�� �� ȭ �� �� �� ��\n");
	for (i = 0; i < startday; i++)
		printf("   ");
	for (i = 1; i <= m[month -1]; i++)
	{
		printf("%2d ", i);
		if ((i + startday) % 7 == 0)
			printf("\n");
	}
	printf("\n");

	return 0;
}