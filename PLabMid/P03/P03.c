#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
	int i, j;
	int index[] = { 0,0,0,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 }; //3~18���� �ֻ��� ��
	int dice; //�ֻ���
	int whole = 30000; //��ü30000��
	int sum; //�ֻ��� ��
	int count[19] = { 0 }; //�ֻ������� ���� Ƚ��
	double prob[19] = { 0.0 }; //Ȯ��

	srand(0);
	while (whole--) {
		sum = 0;
		for (i = 0; i < 3; ++i) {
			dice = rand() % 6 + 1;
			sum += dice;
		}
		++count[sum];
	}

	whole = 30000;
	for (i = 3; i < 19; ++i)
		prob[i] = (double)(count[i]) / whole * 100;

	for (i = 3; i < 19; i++) {

		//�ε���, Ȯ�� ���
		printf("%2d: %5.2lf%% ", index[i], prob[i]);

		//�Ҽ����� ������ �� ���
		if ((prob[i] * 100) - (int)(prob[i]) * 100 > 0)
			printf("*");

		//�ۼ�Ʈ ������ŭ �����
		for (j = 0; j < (int)(prob[i]); j++)
			printf("*");

		printf("\n");
	}
}