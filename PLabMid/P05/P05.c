#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int isFibo(int num)
{
	int i, count = 2;
	long long fibo[100] = { 0,1 };

	for (i = 2; i <= 100; ++i)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		if (fibo[count] >= (long long)(num))
			break;
		++count;
	}

	if (fibo[count] == (long long)(num))
		return 1;
	else
		return 0;
}

void PrintFibo(int num)
{
	int i;
	int count = 2;
	long long fibo[100] = {0,1};

	for (i = 2; i <= 100; ++i)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		if (fibo[count] >= (long long)(num))
			break;
		++count;
	}
	//�Ǻ���ġ �� ���
	printf("%d %I64d %I64d\n", count, fibo[count - 1], fibo[count - 2]);
}

int main() {

	int ntest, num;
	int Fibo;

	scanf("%d", &ntest);
	printf("\n");

	while (ntest--)
	{
		scanf("%d", &num);

		Fibo = isFibo(num);
		//�Ǻ���ġ ���̸�
		if (Fibo)
		{
			PrintFibo(num);
			continue;
		}

		//�Ǻ���ġ ���� �ƴϸ� ��� ���
		if (!Fibo)
			printf("NO\n");
	}
}