// 2017 ���α׷��ַ� - 13��
// 2008�� ACM ����
// Kaprekar �� ����
// 4�ڸ� ���� �Է¹޾� ���ڸ� �迭�ؼ� ���� ���� ū���� ���� ���� ���� ���̸� ���ϰ�
// �� ���� �ٽ� �迭�ؼ� ū�� - ������ ������ �ݺ��ϸ�
// 6174 �� ��������� 6174�� ����� �ִ� �ִ밪-�ּҰ� = 7614 - 1467 = 6174�� �� ���� ������ �ʴ´�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int debug = 0;

// n�� �޾Ƽ� �ִ밪���� �ּҰ��� �� ����� return �Ѵ�.
int kaprekar(int n)
{
	int d[10] = { 0 }; // digit���� �����ϴ� Ƚ�� 
	int i, j, max = 0, min = 0; // digit�� �̿��ؼ� ����� �ִ� �ִ밪, �ּҰ�
	int fourthNum, thirdNum, secondNum, firstNum;

	// digit ���� ���� Ƚ���� ���Ѵ�. 1234 -> ���� �ѹ���, 8822 8�� 2ȸ, 2�� 2ȸ (�ߺ� �����ϴ� �� ó���� ���� �ʿ�)
	fourthNum = n / 1000;
	thirdNum = n % 1000 / 100;
	secondNum = n % 100 / 10;
	firstNum = n % 10;
	
	
	d[fourthNum]++;
	d[thirdNum]++;
	d[secondNum]++;
	d[firstNum]++;

	// �ִ밪�� ���Ѵ�. 	// 9 -> 0���� �������鼭 ���ڵ��� �迭�ϸ� ū���� ���� �� �ִ� (�ߺ� �����ϴ� �� ó���� �߿�)
	
	for (i = 3; i > 0; i--) 
	{
		for (j = 9; j >= 0; j--) 
		{
			if (d[j] != 0) 
			{
				while (d[j]) {
					max += (int)pow(10,i--) * j;
					d[j]--;
				}
				
			}
			if (i < 0)
				break;
		}
	}
	// �ּҰ��� ���Ѵ�.  // 0 -> 9�� �ö󰡸鼭 �迭�ϸ� �������� ���� �� �ִ�. (�ߺ� �����ϴ� �� ó���� �߿�)
	d[fourthNum]++;
	d[thirdNum]++;
	d[secondNum]++;
	d[firstNum]++;

	for (i = 3; i > 0; i--) {
		for (j = 0; j <= 9; j++) {
			if (d[j] != 0) {
				while (d[j]) {
					min += (int)pow(10, i--) * j;
					d[j]--;
				}
			}
			if (i < 0)
				break;
		}
	}

	if (debug)
		printf("%04d - %04d = %04d\n", max, min, max - min);
	return (max - min);
}
void main()
{
	int ntest, n, count, ret;
	printf("Debug ���? (1/0) : "); scanf("%d", &debug);
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%d", &n);
		count = 0;
		ret = -1;
		while (1) {
			ret = kaprekar(n); // ����� �޾Ƽ�
			if (ret == n) { // n�� ret�� ������(6174)
				break;
			}
			else { // �ٽ� ȣ��
				count++;
				n = ret;
			}
		}
		printf("%d\n", count);
	}
}