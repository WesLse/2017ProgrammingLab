#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int isAmicable(int num1, int num2)
{
	int i;
	int SumNum1 = 1;
	int temp;
	//���� -> ���� ū ��� -> ���� ū ���
	//Ƚ�� ���� ����
	temp = num1 / 2;

	for (i = 2; i < temp; ++i)
	{
		if (num1 % i == 0)
		{
			SumNum1 += (i + (num1 / i));
			temp = num1 / i;
		}
	}

	if (SumNum1 == num2)
		return 1;
	else
		return 0;
}

int SumMyDivisor(int num)
{
	int i;
	int isPrime = 1;
	int temp = num / 2;
	int sum = 1;

	//�Ҽ� �Ǻ�
	for (i = 2; i < num / 2; ++i)
	{
		if (num%i == 0)
		{
			isPrime = 0;
			break;
		}
	}

	//�Ҽ��̸� 1 ����
	if (isPrime)
		return sum;
	
	//��� ��
	for (i = 2; i < temp; ++i)
	{
		if (num % i == 0)
		{
			sum += (i + (num / i));
			temp = num / i;
		}
	}

	return sum;
}

int main() {
	
	int ntest, num1, num2;
	int amicablenumber; //ģȭ������ Ȯ��(ģȭ���̸� 1, �ƴϸ� 0)
	
	scanf("%d", &ntest);
	printf("\n");
	
	while (ntest--)
	{
		scanf("%d %d", &num1, &num2);

		amicablenumber = isAmicable(num1, num2);

		//ģȭ���̸�
		if (amicablenumber) 
		{
			printf("YES\n");
			continue;
		}

		//ģȭ���� �ƴϸ� ��� ���
		if (!amicablenumber)
			printf("%d %d\n", SumMyDivisor(num1), SumMyDivisor(num2));
	}
}