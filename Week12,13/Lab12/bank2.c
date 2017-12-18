// 예제: 은행 보안카드 입력 프로그램 작성
// gotoxy()와 textcolor() getch() 를 이용한 version
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h> //윈도우즈와 관련된 것을 처리해주는 입출력 함수입니다.
#include <ctype.h>

#define MIN 11
#define MAX 99
#define N	35
#define ROWS	7
#define COLS	5
// text color define
// 색상 정의
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

void gotoxy(int x, int y)//내가 원하는 위치로 커서 이동
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 문자의 color 설정, foreground | background
void textcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

// 화면 clear
void cls(int fg, int bg)
{
	char buf[80 * 24 + 1] = { 0 };
	int x, y;
	for (x = 0; x < 80; x++)
		for (y = 0; y < 24; y++)
			buf[y * 80 + x] = ' ';

	gotoxy(0, 0);
	textcolor(fg, bg);
	printf(buf);
}

// 사용자가 보는 보안카드, 모두 출력한다.
void print_card(int x, int y, int num[])
{
	int i, j;

	textcolor(BLACK, WHITE);
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("[%02d]:%02d %02d   ", i + ROWS*j + 1, num[i + ROWS*j] / 100, num[i + ROWS*j] % 100);
		}
		printf("\n");
	}
}

// index1: 처음 두자리, index2: 뒤의 두자리 blank로 출력
void print_card2(int x, int y, int num[], int index1, int index2)
{
	gotoxy(x, y);
	int i, j, index;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			if (i + ROWS * j == index1)
			{
				textcolor(RED2, WHITE);
				printf("[%02d]: ** %02d   ", i + ROWS * j+1, num[i + ROWS * j] % 100);
			}
			else if (i + ROWS * j == index2)
			{
				textcolor(BLUE2, WHITE);
				printf("[%02d]: %02d **   ", i + ROWS * j+1, num[i + ROWS * j] / 100);
			}
			else
			{
				textcolor(BLACK, WHITE);
				printf("[%02d]: %02d %02d   ", i + ROWS * j + 1, num[i + ROWS * j] / 100, num[i + ROWS * j] % 100);
			}
		}
		printf("\n");
	}
}

void printxy(int x, int y, char *str)
{
	gotoxy(x, y);
	printf(str);
}

char getdigitxy(int x, int y) // cusor x, y 위치에서 0 ~ 9 만 입력 받는다.
{
	char ch;
	gotoxy(x, y);
	do {
		ch = getch();
	} while (!isdigit(ch));
	putch('*'); // 커서 자리에 * 를 표시
	return ch;
}

void putcharxy(int x, int y, char ch)
{
	gotoxy(x, y);
	putch(ch);
}

void dispbar(int x, int y) // display bar
{
	gotoxy(x, y);
	printf("========");
}
void main()
{
	int num[35] = { 0 };
	int i, j, num1, num2;
	int index1, index2; // 앞의 두자리,  뒤의 두자리 index
	int x1, y1, x2, y2; // 빈칸 처리한 두자리 수들의 좌표
	srand(time(NULL));
	// 보안카드 발생

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
	// 

	cls(BLACK, WHITE); // 화면을 원하는 색으로 clear

	textcolor(BLACK, WHITE);
	printxy(0, 0, "===== 내손의 보안카드 ====\n");
	print_card(0, 1, num);
	textcolor(BLACK, WHITE);
	printxy(0, 8, "===== 인터넷 뱅킹화면 ====\n");

	// 검사할 번호 2개를 생성한다.
	// index1 index2
	while (1)
	{
		index1 = rand() % 35;
		index2 = rand() % 35;
		if (index1 == index2)
			continue;
		else
			break;
	}

	// getch() version
	while (1) {
		char ch1, ch2;

		// 앞의 두자리와 뒤의 두자리를 blank 로 출력	
		// 틀린 경우를 대비해서 다시 출력한다.

		print_card2(0, 9, num, index1, index2);
		printf("======================================\n");


		// 처음 두자리 붉은 색으로 입력하고 보안카드 빈칸에 표시
		x1 = 28; y1 = 17;
		gotoxy(0, y1);
		textcolor(RED2, WHITE);
		printf("[%02d] 번 앞의 두자리 입력 : [  ]**", index1 + 1);
		
		ch1 = getdigitxy(x1, y1);
		ch2 = getdigitxy(x1 + 1, y1);
		num1 = (ch1-'0') * 10 + (ch2-'0');
		printf("\n");

		// 두번째 수 뒤의 두자리 파란색으로 입력
		x2 = 30; y2 = 18;
		gotoxy(0,y2);
		textcolor(BLUE2, WHITE);
		printf("[%02d] 번 뒤의 두자리 입력 : **[  ]", index2 + 1);
	
		ch1 = getdigitxy(x2, y2);
		ch2 = getdigitxy(x2 + 1, y2);
		num2 = (ch1 - '0') * 10 + (ch2 - '0');
		printf("\n");

		textcolor(GREEN2, WHITE);
		if (num[index1] / 100 == num1 && num[index2] % 100 == num2) {
			printxy(0, 20, "맞았습니다.\n");
			break;
		}
		else {
			textcolor(RED2, WHITE);
			printxy(0, 20, "틀렸습니다.\n");
		
		}
	}

	printxy(0, 21, "아무키나 누르면 종료합니다.\n");
	getch();
}
