// 2017년 1학기 프로그래밍랩 5주
// Lab5-3 성적 발생하기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int i, j, n, r;
	int sum = 0; // 총점
	// 학점별 인원수 0:A+, 1:A, ... D, 8:F
	char *grade_str[] = { "A+", "A ", "B+", "B ", "C+", "C ", "D+", "D ", "F " };
	int grade_index, grade_count[9] = { 0 };
	int *scores[9];
	int score1;

	scanf("%d", &n);
	for (i = 0; i < 9; i++)
		scores[i] = (int *)malloc(sizeof(int)*n);
	srand(time(NULL)); // 난수 초기화
	for (i = 0; i < n; i++) {
		score1 = rand() % 101; // 0 ~ 100
		printf("%d ", score1);
		sum += score1;// sum 을 구한다.
		if (score1 >= 95) // grade_index 를 구한다. 0:A+, 1:A ...
			grade_index = 0; //A+
		else if (score1 >= 90) 
			grade_index = 1; //A
		else if (score1 >= 85)
			grade_index = 2; //B+
		else if (score1 >= 80)
			grade_index = 3; //B
		else if (score1 >= 75)
			grade_index = 4; //C+
		else if (score1 >= 70)
			grade_index = 5; //C
		else if (score1 >= 65)
			grade_index = 6; //D+
		else if (score1 >= 60)
			grade_index = 7; //D
		else
			grade_index = 8; //F
		grade_count[grade_index]++;
	}
	printf("\n\nn=%d 평균 = %.2f\n", n, ((double)sum) / n);
	for (i = 0; i < 9; i++) {
		// 화면과 같이 출력
		printf("%s  :%7d (%9.2lf%%)\n",grade_str[i],grade_count[i],((double)grade_count[i])/n *100);
		printf("\n");
	}
}