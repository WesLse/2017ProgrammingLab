#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrimeOrder(int num)
{
	int i;
	int flag; //�Ҽ��� �� 1, �Ҽ��� �ƴ� �� 0;
	int order = 1; //2�� ���� 1�� �ʱ�ȭ
	int count = 2;
	
	//2���� num���� �������
	while (count != num)
	{
		++count; //2�϶� order�� �����������Ƿ� 3���� ���
		flag = 1;

		for (i = 2; i < count; i++)
		{
			if (count % i == 0)
			{
				flag = 0;
				break;
			}
		}

		//�Ҽ��̸� ��������
		if (flag)
			++order;

		//�Ҽ��� �ƴϸ� ���
		if (!flag)
			continue;
	}
	return order;
}


int main() {
	int i, ntest, num, isPrimeFlag;
	scanf("%d", &ntest);
	printf("\n");
	while (ntest--)
	{
		scanf("%d", &num);
		isPrimeFlag = 1; //�Ҽ��̸� 1, �ƴϸ� 0

		//�Ҽ��� �ƴϸ� isPrimeFlag�� 0����
		for (i = 2; i < (num / 2); i++)
			if (num%i == 0)
				isPrimeFlag = 0;

		//�Ҽ��� �ƴϸ� NO ���
		if (!isPrimeFlag)
		{
			printf("NO\n");
			continue;
		}

		printf("%d\n", isPrimeOrder(num));
	}

}