// 2017년 1학기 프로그래밍랩 5주
// Lab5-3 150명 성적 분포에 맞게 점수 발생시키기
// A+(95~100): 10%, A(90~94):10%, B+(85~89):20%, B(80~84):25%, 
// C+(75~79):15%, C(70~74):10%, D+(65~69):5%, D(60~64):3%, F:2%
// Lab5-3 을 참조하여 작성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RANDMAX 32767
#define RANMIN 0

void main()
{
	int i, j, n, score1;
	int sum = 0; // 총점
	char *grade_str[] = { "A+", "A ", "B+", "B ", "C+", "C ", "D+", "D ", "F " };
	int count[9] = { 0 }; //등급별 배정인원
	double max;
	int maxcount[9]; // 최대인원
	int start[9] = { 95,90,85,80,75,70,65,60,0 };
	int end[9] = { 100,94,89,84,79,74,69,64,59 };
	int dist[9] = { 10, 10, 20, 25, 15, 10, 5, 3, 2 };//등급 퍼센트

	//인원
	scanf("%d", &n);

	srand(time(NULL));


	//등급별 인원제한 계산
	for (i = 0; i < 9; i++) {
		max = (double)(n)* dist[i] / 100;
		max = ceil(max);
		maxcount[i] = max;
	}


	//점수 생성 및 등급별 인원 배정
	for (i = 0; i < n; i++) {
	
	re:
		score1 = rand() % 101;

		if (start[0] <= score1) {
			count[0]++;
			if (count[0] > maxcount[0]) {
				--count[0];
				goto re;
			}
		}
		else if (start[1] <= score1) {
			count[1]++;
			if (count[1] > maxcount[1]) {
				--count[1];
				goto re;
			}
		}
		else if (start[2] <= score1) {
			count[2]++;
			if (count[2] > maxcount[2]) {
				--count[2];
				goto re;
			}
		}
		else if (start[3] <= score1) {
			count[3]++;
			if (count[3] > maxcount[3]) {
				--count[3];
				goto re;
			}
		}
		else if (start[4] <= score1) {
			count[4]++;
			if (count[4] > maxcount[4]) {
				--count[4];
				goto re;
			}
		}
		else if (start[5] <= score1) {
			count[5]++;
			if (count[5] > maxcount[5]) {
				--count[5];
				goto re;
			}
		}
		else if (start[6] <= score1) {
			count[6]++;
			if (count[6] > maxcount[6]) {
				--count[6];
				goto re;
			}
		}
		else if (start[7] <= score1) {
			count[7]++;
			if (count[7] > maxcount[7]) {
				--count[7];
				goto re;
			}
		}
		else {
			count[8]++;
			if (count[8] > maxcount[8]) {
				--count[8];
				goto re;
			}
		}

		sum += score1;

		printf("%d  ", score1);
	}

	printf("\n\n");
	printf("n = %d  평균 = %.2lf\n", n, ((double)sum) / n);
	
	for (i = 0; i < 9; i++) 
		printf("%s  : %7d (%5.2lf%%)\n", grade_str[i], 
			count[i], ((double)count[i]) / n * 100);
}