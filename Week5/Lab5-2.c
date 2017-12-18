// 2017�� 1�б� ���α׷��ַ� 5��
// Lab5-2 �ֻ��� 
// (1) n�� ������ ������ ���� �߻� Ȯ�� ����� ����
// (2) Ȯ���� ���۵� �ֻ��� 
//		1~5 = 10%, 6 = 50% ��, 6�� ���� ������ �ֻ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i, r, ntest, dice;
	int count[6] = { 0 }; // 1 ~ 6 count �� ����
	srand(time(NULL)); // ���� �ʱ�ȭ
	printf("�ֻ��� Ƚ�� : ");
	scanf("%d", &ntest);
	printf("�������� �ֻ���\n");
	for (i = 0; i < ntest; i++) {
		r = rand() % 6; //?? 0~5 -> �ֻ��� 1~6
		++count[r]; //�߻� ȸ�� ����, �ϼ��� ��
	}

	for (i = 0; i < 6; i++) {
		printf("%d : %d (%.2lf%%)\n", i + 1, count[i], (((double)count[i]) / ntest) * 100);// ȭ��� ���� ���	
	}


	printf("\n");

	// �̻��� �ֻ���
	printf("\n�̻��� �ֻ��� 6�� 50% Ȯ��\n");
	for (i = 0; i < 6; i++)
		count[i] = 0;
	for (i = 0; i < ntest; i++) {
		r = rand() % 10; // ������ 0~9�� ���ϰ� 0, 1, .. 9 (�ֻ��� 1,2,3,4,5,6,6,6,6,6)
		if (r > 5)
			r = 5;	// 5, 6, 7, 8, 9 ==> 5 �� 6�� ���� Ȯ�� 1/2
		++count[r];// �߻� ȸ�� ����
	}
	for (i = 0; i < 6; i++) {
		printf("%d : %d (%.2lf%%)\n", i + 1, count[i], (((double)count[i]) / ntest) * 100);// ȭ��� ���� ���
	}

}