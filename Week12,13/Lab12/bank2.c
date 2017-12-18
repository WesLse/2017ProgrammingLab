// ����: ���� ����ī�� �Է� ���α׷� �ۼ�
// gotoxy()�� textcolor() getch() �� �̿��� version
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h> //��������� ���õ� ���� ó�����ִ� ����� �Լ��Դϴ�.
#include <ctype.h>

#define MIN 11
#define MAX 99
#define N	35
#define ROWS	7
#define COLS	5
// text color define
// ���� ����
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

void gotoxy(int x, int y)//���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ������ color ����, foreground | background
void textcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

// ȭ�� clear
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

// ����ڰ� ���� ����ī��, ��� ����Ѵ�.
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

// index1: ó�� ���ڸ�, index2: ���� ���ڸ� blank�� ���
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

char getdigitxy(int x, int y) // cusor x, y ��ġ���� 0 ~ 9 �� �Է� �޴´�.
{
	char ch;
	gotoxy(x, y);
	do {
		ch = getch();
	} while (!isdigit(ch));
	putch('*'); // Ŀ�� �ڸ��� * �� ǥ��
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
	int index1, index2; // ���� ���ڸ�,  ���� ���ڸ� index
	int x1, y1, x2, y2; // ��ĭ ó���� ���ڸ� ������ ��ǥ
	srand(time(NULL));
	// ����ī�� �߻�

	for (i = 0; i < N; i++) { // 35�� ���� �߻�
							  // num1, num2 = 11 ~ 99
		num1 = rand() % 89 + 11;
		num2 = rand() % 89 + 11;
		num[i] = num1 * 100 + num2;
		// ��ĭ �ȿ��� 2�ڸ��� ���� ���� �����ؾ���
		if (num1 == num2) {
			--i;
			continue;
		}
		// 35�� ���� ���� ���� �߻��ϴ� ���� �����ؾ� ��
		for (j = 0; j < i; j++) {
			if (num[j] == num[i]) {
				--i;
				break;
			}
		}
	}
	// 

	cls(BLACK, WHITE); // ȭ���� ���ϴ� ������ clear

	textcolor(BLACK, WHITE);
	printxy(0, 0, "===== ������ ����ī�� ====\n");
	print_card(0, 1, num);
	textcolor(BLACK, WHITE);
	printxy(0, 8, "===== ���ͳ� ��ŷȭ�� ====\n");

	// �˻��� ��ȣ 2���� �����Ѵ�.
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

		// ���� ���ڸ��� ���� ���ڸ��� blank �� ���	
		// Ʋ�� ��츦 ����ؼ� �ٽ� ����Ѵ�.

		print_card2(0, 9, num, index1, index2);
		printf("======================================\n");


		// ó�� ���ڸ� ���� ������ �Է��ϰ� ����ī�� ��ĭ�� ǥ��
		x1 = 28; y1 = 17;
		gotoxy(0, y1);
		textcolor(RED2, WHITE);
		printf("[%02d] �� ���� ���ڸ� �Է� : [  ]**", index1 + 1);
		
		ch1 = getdigitxy(x1, y1);
		ch2 = getdigitxy(x1 + 1, y1);
		num1 = (ch1-'0') * 10 + (ch2-'0');
		printf("\n");

		// �ι�° �� ���� ���ڸ� �Ķ������� �Է�
		x2 = 30; y2 = 18;
		gotoxy(0,y2);
		textcolor(BLUE2, WHITE);
		printf("[%02d] �� ���� ���ڸ� �Է� : **[  ]", index2 + 1);
	
		ch1 = getdigitxy(x2, y2);
		ch2 = getdigitxy(x2 + 1, y2);
		num2 = (ch1 - '0') * 10 + (ch2 - '0');
		printf("\n");

		textcolor(GREEN2, WHITE);
		if (num[index1] / 100 == num1 && num[index2] % 100 == num2) {
			printxy(0, 20, "�¾ҽ��ϴ�.\n");
			break;
		}
		else {
			textcolor(RED2, WHITE);
			printxy(0, 20, "Ʋ�Ƚ��ϴ�.\n");
		
		}
	}

	printxy(0, 21, "�ƹ�Ű�� ������ �����մϴ�.\n");
	getch();
}
