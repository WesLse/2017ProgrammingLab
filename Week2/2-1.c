#include <stdio.h>

int isPrime(int n)
{
	int i;

	for (i = 2; i < (n/2); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i, sum = 0;
	for (i = 2; i <= 100; i++) {
		if (isPrime(i) == 1) {
			printf("%d ", i);
			//isPrime()�� �̿��ؼ� �ڼ��̸� ����ϰ� sum�� ���Ѵ�.
			sum += i;
		}
	}
	printf("\n");
	printf("sum=%d\n",sum);

	return 0;

}