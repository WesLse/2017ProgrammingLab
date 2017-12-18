// ����: ���� ����ī�� �Է� ���α׷� �ۼ�
// printf() �� ����� Version
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MIN 01
#define MAX 99
#define N	35
#define ROWS	7
#define COLS	5


void main()
{
	int num[35] = { 0 }; // ī�� �� = num1*100 + num2
	int i, j, num1, num2; // num1 �� �� 2�ڸ�, num2�� �� ���ڸ�
	int index1, index2; // index1�� ���ڸ� üũ��, index2�� ���ڸ� üũ��
	srand(time(NULL));

	for (i = 0; i < N; i++) { // 35�� ���� �߻�
		// num1, num2 = 11 ~ 99
		num1 = rand() % 89 + 11;
		num2 = rand() % 89 + 11;
		num[i] = num1 * 100 + num2;
		// ��ĭ �ȿ��� 2�ڸ��� ���� ���� �����ؾ���
		if (num1 == num2) {
			--i;
			continue;
		}
		// 35�� ���� ���� ���� �߻��ϴ� ���� �����ؾ� ��
		for (j = 0; j < i; j++) {
			if (num[j] == num[i]) {
				--i;
				break;
			}
		}
	}

	// ����ī�� ���
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++)
			printf("[%02d]:%02d %02d   ", i+ ROWS*j+1, num[i + ROWS*j] / 100, num[i + ROWS*j] % 100);
		printf("\n");
	}

	// �˻� �κ�
	// index1 = ?? // ���� ���ڸ�
	// index2 = ���� ���ڸ�
	// index1 �� index2�� ������ �ȵ�
	while (1)
	{
		index1 = rand() % 35;
		index2 = rand() % 35;
		if (index1 == index2)
			continue;
		else
			break;
	}

	// scanf version
	while (1) {
		printf("=================================\n");
		
		// index1, index2�� �ش��ϴ� num1, num2�� �Է¹ް� 
		printf("[%02d] �� ���� ���ڸ� �Է� : ", index1+1);
		scanf("%d", &num1);
		printf("[%02d] �� ���� ���ڸ� �Է� : ", index2+1);
		scanf("%d", &num2);
		// �ٸ��� ���������� �ݺ��ϰ� ������ ����
		if ((num[index1] / 100 == num1) && (num[index2] % 100 == num2)) {
			printf("�¾ҽ��ϴ�.\n");
			exit(1);
		}
		else
			printf("�ٽ� �Է��ϼ���.\n");
	}

}
