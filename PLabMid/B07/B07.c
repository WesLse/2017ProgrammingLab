#define _CRT_SECURE_NO_WARNINGS

#define SPACE 1
#define HEART 2
#define DIAMOND 3
#define CLOVER 4
#define A 11
#define J 10
#define Q 10
#define K 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int player[6][2] = { (0,0) }; //플레이어(카드 모양, 카드 숫자)
	int category[] = { SPACE, HEART, DIAMOND, CLOVER }; //카드 모양
	int card[] = { A,2,3,4,5,6,7,8,9,10,J,Q,K }; //카드 숫자
	int temp[6][2] = { (0,0) }; //처음 뽑은 카드 저장
	double prob[6] = { 0 }; //루프중에는 뽑은 횟수 배열, 루프끝나면 확률 배열
	int count = 1000000;  //총 횟수
	int i, j, random;

	srand(time(NULL)); //무작위

	while (count--)
	{
		for (i = 0; i < 6; ++i)
		{
		back1:
			random = rand() % 4;				//모양 뽑기
			player[i][0] = category[random];

			random = rand() % 13;				//숫자 뽑기
			player[i][1] = card[random];

			//이전에 뽑은 것과 같으면 다시
			for (j = 0; j < i; ++j)
			{
				if (((player[i][0] == player[j][0]) && (player[i][1] == player[j][1])) || ((temp[j][0] == player[i][0]) && (temp[j][1] == player[i][1])))
				{
					goto back1;
				}
			}

			temp[i][0] = player[i][0];
			temp[i][1] = player[i][1];

		back2:
			random = rand() % 4;
			player[i][0] = category[random];

			random = rand() % 13;
			player[i][1] = card[random];
			
			//이전에 뽑은 것과 같으면 다시
			for (j = 0; j < i; ++j)
			{
				if (((player[i][0] == player[j][0]) && (player[i][1] == player[j][1])) || ((temp[j][0] == player[i][0]) && (temp[j][1] == player[i][1])))
				{
					goto back2;
				}
			}

			if (temp[i][1] + player[i][1] == 21) //처음에 뽑은 카드의 숫자와 두번째로 뽑은 카드의 숫자의 합이 블랙잭이면
				prob[i]++;
		}
	}

	count = 1000000; // 전체횟수 초기화

	//확률계산
	for (i = 0; i < 6; ++i)
		prob[i] = prob[i] / count * 100;

	for (i = 0; i < 6; ++i)
	{
		if (i == 0)
			printf("       딜러 = %.02lf%%\n", prob[i]);

		printf("플레이어[%d] = %.02lf%%\n", i, prob[i]);
	}
}