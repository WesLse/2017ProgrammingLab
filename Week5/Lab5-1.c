// 2017�� 1�б� ���α׷��ַ� 5��
// Lab5-1 ���� n�� (start ~ end) �߻���Ű�� �հ� ��� ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i, n, r, sum = 0;
	int start, end;
	srand(time(NULL)); // ������ �ʱ�ȭ
	printf("������ ����: ");
	scanf("%d", &n);
	printf("���۰� �� : ");
	scanf("%d %d", &start, &end);
	
	for (i = 0; i < n; i++) {
		r = rand();
		r = start + rand() % (end - start + 1);
		printf("%d ", r);
		sum += r;
	}
	printf("\nsum=%d avg=%d\n", sum, sum / n);

}