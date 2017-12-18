// 2017 프로그래밍랩 - 13주
// 2008년 ACM 문제
// Kaprekar 의 연산
// 4자리 수를 입력받아 숫자를 배열해서 만든 가장 큰수와 가장 작은 수의 차이를 구하고
// 그 수를 다시 배열해서 큰수 - 작은수 과정을 반복하면
// 6174 가 만들어지고 6174로 만들수 있는 최대값-최소값 = 7614 - 1467 = 6174로 그 값은 변하지 않는다

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int debug = 0;

// n을 받아서 최대값에서 최소값을 뺀 결과를 return 한다.
int kaprekar(int n)
{
	int d[10] = { 0 }; // digit들이 등장하는 횟수 
	int i, j, max = 0, min = 0; // digit을 이용해서 만들수 있는 최대값, 최소값
	int fourthNum, thirdNum, secondNum, firstNum;

	// digit 들의 등장 횟수를 구한다. 1234 -> 각각 한번씩, 8822 8이 2회, 2가 2회 (중복 등장하는 수 처리를 위해 필요)
	fourthNum = n / 1000;
	thirdNum = n % 1000 / 100;
	secondNum = n % 100 / 10;
	firstNum = n % 10;
	
	
	d[fourthNum]++;
	d[thirdNum]++;
	d[secondNum]++;
	d[firstNum]++;

	// 최대값을 구한다. 	// 9 -> 0으로 내려오면서 숫자들을 배열하면 큰수를 구할 수 있다 (중복 등장하는 수 처리가 중요)
	
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
	// 최소값을 구한다.  // 0 -> 9로 올라가면서 배열하면 작은수를 구할 수 있다. (중복 등장하는 수 처리가 중요)
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
	printf("Debug 모드? (1/0) : "); scanf("%d", &debug);
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%d", &n);
		count = 0;
		ret = -1;
		while (1) {
			ret = kaprekar(n); // 결과를 받아서
			if (ret == n) { // n이 ret와 같으면(6174)
				break;
			}
			else { // 다시 호출
				count++;
				n = ret;
			}
		}
		printf("%d\n", count);
	}
}