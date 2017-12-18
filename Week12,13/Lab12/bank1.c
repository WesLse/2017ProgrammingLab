// 예제: 은행 보안카드 입력 프로그램 작성
// printf() 만 사용한 Version
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MIN 01
#define MAX 99
#define N	35
#define ROWS	7
#define COLS	5


void main()
{
	int num[35] = { 0 }; // 카드 수 = num1*100 + num2
	int i, j, num1, num2; // num1 은 앞 2자리, num2는 뒤 두자리
	int index1, index2; // index1은 앞자리 체크용, index2는 뒷자리 체크용
	srand(time(NULL));

	for (i = 0; i < N; i++) { // 35개 난수 발생
		// num1, num2 = 11 ~ 99
		num1 = rand() % 89 + 11;
		num2 = rand() % 89 + 11;
		num[i] = num1 * 100 + num2;
		// 한칸 안에서 2자리가 같은 것을 방지해야함
		if (num1 == num2) {
			--i;
			continue;
		}
		// 35개 수중 같은 수가 발생하는 것을 방지해야 함
		for (j = 0; j < i; j++) {
			if (num[j] == num[i]) {
				--i;
				break;
			}
		}
	}

	// 보안카드 출력
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++)
			printf("[%02d]:%02d %02d   ", i+ ROWS*j+1, num[i + ROWS*j] / 100, num[i + ROWS*j] % 100);
		printf("\n");
	}

	// 검사 부분
	// index1 = ?? // 앞의 두자리
	// index2 = 뒤의 두자리
	// index1 과 index2가 같으면 안됨
	while (1)
	{
		index1 = rand() % 35;
		index2 = rand() % 35;
		if (index1 == index2)
			continue;
		else
			break;
	}

	// scanf version
	while (1) {
		printf("=================================\n");
		
		// index1, index2에 해당하는 num1, num2를 입력받고 
		printf("[%02d] 번 앞의 두자리 입력 : ", index1+1);
		scanf("%d", &num1);
		printf("[%02d] 번 뒤의 두자리 입력 : ", index2+1);
		scanf("%d", &num2);
		// 다르면 맞을때까지 반복하고 같으면 종료
		if ((num[index1] / 100 == num1) && (num[index2] % 100 == num2)) {
			printf("맞았습니다.\n");
			exit(1);
		}
		else
			printf("다시 입력하세요.\n");
	}

}
