#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int isAmicable(int num1, int num2)
{
	int i;
	int SumNum1 = 1;
	int temp;
	//절반 -> 가장 큰 약수 -> 다음 큰 약수
	//횟수 감소 역할
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

	//소수 판별
	for (i = 2; i < num / 2; ++i)
	{
		if (num%i == 0)
		{
			isPrime = 0;
			break;
		}
	}

	//소수이면 1 리턴
	if (isPrime)
		return sum;
	
	//약수 합
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
	int amicablenumber; //친화수인지 확인(친화수이면 1, 아니면 0)
	
	scanf("%d", &ntest);
	printf("\n");
	
	while (ntest--)
	{
		scanf("%d %d", &num1, &num2);

		amicablenumber = isAmicable(num1, num2);

		//친화수이면
		if (amicablenumber) 
		{
			printf("YES\n");
			continue;
		}

		//친화수가 아니면 약수 출력
		if (!amicablenumber)
			printf("%d %d\n", SumMyDivisor(num1), SumMyDivisor(num2));
	}
}