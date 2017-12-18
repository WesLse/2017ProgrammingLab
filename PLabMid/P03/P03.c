#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
	int i, j;
	int index[] = { 0,0,0,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 }; //3~18까지 주사위 합
	int dice; //주사위
	int whole = 30000; //전체30000번
	int sum; //주사위 합
	int count[19] = { 0 }; //주사휘합이 나온 횟수
	double prob[19] = { 0.0 }; //확률

	srand(0);
	while (whole--) {
		sum = 0;
		for (i = 0; i < 3; ++i) {
			dice = rand() % 6 + 1;
			sum += dice;
		}
		++count[sum];
	}

	whole = 30000;
	for (i = 3; i < 19; ++i)
		prob[i] = (double)(count[i]) / whole * 100;

	for (i = 3; i < 19; i++) {

		//인덱스, 확률 찍기
		printf("%2d: %5.2lf%% ", index[i], prob[i]);

		//소수점이 있으면 별 찍기
		if ((prob[i] * 100) - (int)(prob[i]) * 100 > 0)
			printf("*");

		//퍼센트 정수만큼 별찍기
		for (j = 0; j < (int)(prob[i]); j++)
			printf("*");

		printf("\n");
	}
}