// 2017년 1학기 프로그래밍랩 5주
// Lab5-2 주사위 
// (1) n번 던져서 각각의 수의 발생 확률 계산해 보기
// (2) 확률이 조작된 주사위 
//		1~5 = 10%, 6 = 50% 즉, 6이 자주 나오는 주사위
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i, r, ntest, dice;
	int count[6] = { 0 }; // 1 ~ 6 count 를 보관
	srand(time(NULL)); // 난수 초기화
	printf("주사위 횟수 : ");
	scanf("%d", &ntest);
	printf("정상적인 주사위\n");
	for (i = 0; i < ntest; i++) {
		r = rand() % 6; //?? 0~5 -> 주사위 1~6
		++count[r]; //발생 회수 증가, 완성할 것
	}

	for (i = 0; i < 6; i++) {
		printf("%d : %d (%.2lf%%)\n", i + 1, count[i], (((double)count[i]) / ntest) * 100);// 화면과 같이 출력	
	}


	printf("\n");

	// 이상한 주사위
	printf("\n이상한 주사위 6이 50% 확률\n");
	for (i = 0; i < 6; i++)
		count[i] = 0;
	for (i = 0; i < ntest; i++) {
		r = rand() % 10; // 분포를 0~9로 구하고 0, 1, .. 9 (주사위 1,2,3,4,5,6,6,6,6,6)
		if (r > 5)
			r = 5;	// 5, 6, 7, 8, 9 ==> 5 즉 6이 나올 확률 1/2
		++count[r];// 발생 회수 증가
	}
	for (i = 0; i < 6; i++) {
		printf("%d : %d (%.2lf%%)\n", i + 1, count[i], (((double)count[i]) / ntest) * 100);// 화면과 같이 출력
	}

}