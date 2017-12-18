#define _CRT_SECURE_NO_WARNINGS

#define SPACE 1
#define HEART 2
#define DIAMOND 3
#define CLOVER 4
#define A 11
#define J 10
#define Q 10
#define K 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int player[6][2] = { (0,0) }; //�÷��̾�(ī�� ���, ī�� ����)
	int category[] = { SPACE, HEART, DIAMOND, CLOVER }; //ī�� ���
	int card[] = { A,2,3,4,5,6,7,8,9,10,J,Q,K }; //ī�� ����
	int temp[6][2] = { (0,0) }; //ó�� ���� ī�� ����
	double prob[6] = { 0 }; //�����߿��� ���� Ƚ�� �迭, ���������� Ȯ�� �迭
	int count = 1000000;  //�� Ƚ��
	int i, j, random;

	srand(time(NULL)); //������

	while (count--)
	{
		for (i = 0; i < 6; ++i)
		{
		back1:
			random = rand() % 4;				//��� �̱�
			player[i][0] = category[random];

			random = rand() % 13;				//���� �̱�
			player[i][1] = card[random];

			//������ ���� �Ͱ� ������ �ٽ�
			for (j = 0; j < i; ++j)
			{
				if (((player[i][0] == player[j][0]) && (player[i][1] == player[j][1])) || ((temp[j][0] == player[i][0]) && (temp[j][1] == player[i][1])))
				{
					goto back1;
				}
			}

			temp[i][0] = player[i][0];
			temp[i][1] = player[i][1];

		back2:
			random = rand() % 4;
			player[i][0] = category[random];

			random = rand() % 13;
			player[i][1] = card[random];
			
			//������ ���� �Ͱ� ������ �ٽ�
			for (j = 0; j < i; ++j)
			{
				if (((player[i][0] == player[j][0]) && (player[i][1] == player[j][1])) || ((temp[j][0] == player[i][0]) && (temp[j][1] == player[i][1])))
				{
					goto back2;
				}
			}

			if (temp[i][1] + player[i][1] == 21) //ó���� ���� ī���� ���ڿ� �ι�°�� ���� ī���� ������ ���� �����̸�
				prob[i]++;
		}
	}

	count = 1000000; // ��üȽ�� �ʱ�ȭ

	//Ȯ�����
	for (i = 0; i < 6; ++i)
		prob[i] = prob[i] / count * 100;

	for (i = 0; i < 6; ++i)
	{
		if (i == 0)
			printf("       ���� = %.02lf%%\n", prob[i]);

		printf("�÷��̾�[%d] = %.02lf%%\n", i, prob[i]);
	}
}