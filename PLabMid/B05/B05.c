#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrimeOrder(int num)
{
	int i;
	int flag; //소수일 때 1, 소수가 아닐 때 0;
	int order = 1; //2일 때는 1로 초기화
	int count = 2;
	
	//2부터 num까지 순서계산
	while (count != num)
	{
		++count; //2일때 order는 정해져있으므로 3부터 계산
		flag = 1;

		for (i = 2; i < count; i++)
		{
			if (count % i == 0)
			{
				flag = 0;
				break;
			}
		}

		//소수이면 순서증가
		if (flag)
			++order;

		//소수가 아니면 통과
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
		isPrimeFlag = 1; //소수이면 1, 아니면 0

		//소수가 아니면 isPrimeFlag를 0으로
		for (i = 2; i < (num / 2); i++)
			if (num%i == 0)
				isPrimeFlag = 0;

		//소수가 아니면 NO 출력
		if (!isPrimeFlag)
		{
			printf("NO\n");
			continue;
		}

		printf("%d\n", isPrimeOrder(num));
	}

}