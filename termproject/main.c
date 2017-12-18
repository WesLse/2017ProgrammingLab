/*


		Created By LSE


*/




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>




/*------------define-------------*/

// ���� ����
#define BLACK      0
#define BLUE1      1
#define GREEN1     2
#define CYAN1      3
#define RED1       4
#define MAGENTA1   5
#define YELLOW1    6
#define GRAY1      7
#define GRAY2      8
#define BLUE2      9
#define GREEN2    10
#define CYAN2     11
#define RED2      12
#define MAGENTA2  13
#define YELLOW2   14
#define WHITE     15

#define BLANK ' '    // ' ' ���ϸ� ������ �������� 
#define GRASS '-'    // �ٴ�

#define ESC 0x1b     // ESC
#define SPACE 0x20   // Space Bar
#define SmallR 0x72  // r

#define WIDTH 99     // �ܼ�â ����
#define HEIGHT 25    // �ܼ�â ����

#define SPIKE '^'    //��ֹ�

typedef enum { false, true } bool;  //bool Ÿ�� ����

#define true (1)     //true
#define false (0)    //false




/*------------------Struct Prototype-------------------*/
typedef struct _colorset colorset;
typedef struct Player Player;
typedef struct Map Map;




/*------------------Funtion Prototype-------------------*/

//System Contol Function
void RemoveCursor();
void SetFont(const char *font, short fontsize);
void gotoxy(short x, short y);
void ControlWindowConsole();
void textcolor(int fg_color, int bg_color);
void cls(int bg_color, int text_color);
void SetColor(colorset *c);
void SetConsoleName();

//Player Function
void InitPlayer(Player *p);
void Jump(Player *p);
void UpdatePlayer(Player *p, float deltas);
int IsPlayerJumping(Player *p);
void RunFaster(Player *p);
void RenderPlayer(Player *p);
void ErasePlayer(Player *p);
void PrintColideShape(Player *p, bool keepGoing);

//Map Function
void InitMap(Map *m);
void UpdateMap(Map *m, int x);
void RenderMap(Map *m);
int IsXCoordSafe(Map *m, int x);
bool IsPlayerSafe(Map *m, Player *p);

//InGame Funtion
void PrintGameName();
void PrintGameOver();
void InitGame();
int SetHighscore(int highscore, int score);
void RunGame();
bool IsRetry();
void ExitGame();



/*------------------Constants Prototype-------------------*/


extern const colorset cs[10];
extern const char playerShape[6]; //���
extern const char playerJumped[6]; //�������� ��
extern const char playerColideShape[6]; //�浹����
extern const char playerErased[6]; //�÷��̾� �����






 /*------------------Struct Definitions-------------------*/

//�÷��̾�
typedef struct Player {
	float mid_x;
	float left_x;
	float right_x;
	float real_x;
	float y;

	float velo_y;
	float velo_x;

	int score;
}Player;



//��
typedef struct Map {
	//char mapdata[0][WIDTH + 1]; //one for end of string
	//char mapdata[1][WIDTH + 1]; //these can be converted to 2d-array
	char mapdata[2][WIDTH + 1];
	int frontmapbuffer;
	int lastx;
}Map;



//�� ����
typedef struct _colorset {
	WORD bgc, tc;
}colorset;




/*------------------Constant Definitions-------------------*/

//�߷� ���
const float gravity = -20.f;

//����
const colorset cs[10] = {
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE },
	{ BLACK, WHITE } };



//ĳ���� ���
const char playerShape[6] = "r>_>J"; //���
const char playerJumped[6] = "r0_0J"; //�������� ��
const char playerColideShape[6] = "\\x_x/"; //�浹����
const char playerErased[6] = "     "; //�÷��̾� �����






/*-------------------main �Լ�----------------*/

int main() {
	unsigned char key_input;
	InitGame();
	key_input = _getch();
	if (key_input == SPACE)
		RunGame();
	else
		ExitGame();
}









/*-------------------Player--------------------*/

//�÷��̾� �ʱ�ȭ
void InitPlayer(Player *p) {
	p->mid_x = 4;
	p->left_x = p->mid_x - strlen(playerShape) / 2;
	p->right_x = p->mid_x + strlen(playerShape) / 2;
	p->real_x = 0;
	p->y = 12;
	p->velo_x = 10;
	p->velo_y = 0;
	p->score = 0;
}

//����
void Jump(Player *p) {
	if (p->y <= 12) {
		p->y = 12;
		p->velo_y = 15;
	}
}

//����, ��Ÿ��
void UpdatePlayer(Player *p, float deltas) {
	if (p->y < 12 || p->velo_y != 0) {
		p->velo_y += deltas * gravity;
		p->y -= deltas * p->velo_y;
	}
	if (p->velo_y <= 0 && p->y >= 12) {
		p->velo_y = 0;
		p->y = 12;
	}
	p->real_x += p->velo_x * deltas;
}

//�����ϰ� ������ 1, or 0
int IsPlayerJumping(Player *p) {
	return (p->y < 12 || p->velo_y != 0) ? 1 : 0;
}

//�ӵ��ø�
void RunFaster(Player *p) {
	p->velo_x *= 1.001f; //1.001f
}

//�÷��̾� �׸�
void RenderPlayer(Player *p) {
	gotoxy((short)p->left_x, (short)p->y);

	if (IsPlayerJumping(p))
		printf("%s", playerJumped);
	else
		printf("%s", playerShape);
}

//�÷��̾� �����
void ErasePlayer(Player *p) {
	gotoxy((short)p->left_x, (short)p->y);
	printf("%s", playerErased);
}

//ĳ���� �浹 ���
void PrintColideShape(Player *p, bool keepGoing) {
	if (!keepGoing) {
		gotoxy((short)p->left_x, (short)p->y);
		printf("%s", playerColideShape);
		Sleep(500);
	}
}





/*------------------Map--------------------*/

//���ʱ�ȭ
void InitMap(Map *m) {
	m->frontmapbuffer = 1;
	memset(m->mapdata[0], GRASS, WIDTH);
	m->mapdata[0][WIDTH] = 0;
	memcpy(m->mapdata[1], m->mapdata[0], sizeof(char)*(WIDTH + 1));
	m->lastx = 0;
}

//�� ������Ʈ
void UpdateMap(Map *m, int x) {
	int deltax = x - m->lastx;
	m->lastx = x;
	if (deltax > 0) {
		if (m->frontmapbuffer) {
			memcpy(m->mapdata[1], &(m->mapdata[0][deltax]), WIDTH - deltax);
			memset(&(m->mapdata[1][WIDTH - deltax]), GRASS, deltax);
			m->frontmapbuffer = 0;
		}
		else {
			memcpy(m->mapdata[0], &(m->mapdata[1][deltax]), WIDTH - deltax);
			memset(&(m->mapdata[0][WIDTH - deltax]), GRASS, deltax);
			m->frontmapbuffer = 1;
		}
	}
}

//�ʱ׸���
void RenderMap(Map *m) {
	char mapdata[WIDTH + 1] = { 0, };
	memcpy(mapdata, m->mapdata[m->frontmapbuffer], WIDTH + 1);
	int i;
	for (i = 0; i < WIDTH + 1; i++)
	{
		if (mapdata[i] == '-')
			mapdata[i] = ' ';
	}
	textcolor(GREEN2, BLACK);
	gotoxy(0, 12);
	printf("%s", mapdata);
	gotoxy(0, 13);
	printf("%s", m->mapdata[m->frontmapbuffer]);
	textcolor(WHITE, BLACK);
}

//������ũ �����
void makespikes(Map *m) {
	if (m->frontmapbuffer)
		m->mapdata[0][WIDTH - 1] = SPIKE;
	else
		m->mapdata[1][WIDTH - 1] = SPIKE;
}

//�÷��̾�� GRASS�� x��ǥ �� �װ� 0 ��� 1
int IsXCoordSafe(Map *m, int x) {
	if (m->frontmapbuffer)
		return (m->mapdata[0][x] == GRASS) ? 1 : 0;
	else
		return (m->mapdata[1][x] == GRASS) ? 1 : 0;
}

//�÷��̾� ���� ����
bool IsPlayerSafe(Map *m, Player *p) {
	int i;
	for (i = (int)p->left_x; i <= (int)p->right_x; i++) {
		if (!IsXCoordSafe(m, i) && !(IsPlayerJumping(p))) {
			return false;
		}
	}
	return true;
}






/*----------------GAME CONTROL-----------------*/

//���� ���� ���
void PrintGameName() { //Hansung Life
	FILE *gn;
	gn = fopen("GameName.txt", "r");
	char gamenamePrint[200];
	int i = 0;
	textcolor(WHITE, BLUE1);
	while (!feof(gn)) {
		//printf("%d", i);
		fgets(gamenamePrint, 200, gn);
		gotoxy(16, i + 1);
		printf("%s", gamenamePrint);
		i++;
	}
	textcolor(WHITE, BLACK);
	gotoxy(36, 12);
	printf("Press SPACE BAR to Start\n\n");
	gotoxy(40, 15);
	printf("Press ESC to exit\n");
	textcolor(BLACK, WHITE);
	fclose(gn);
}

//���� �ʱ�ȭ
void InitGame() {
	SetConsoleName();
	RemoveCursor();
	cls(WHITE, BLACK);
	ControlWindowConsole();
	SetFont("NSimSun", 16);
	PrintGameName();
	srand((UINT)time(NULL));
}

//���� ����
void RunGame() {
	Player p;               //�÷��̾�
	Map m;                  //��
	float gamespeed = 1.2f;  //���� �ӵ�
	bool keepGoing = true;  //���� ���� ����
	clock_t tMainStart, tMainEnd;	//���� ���� �� ���۽ð�, �� �ð�
	const unsigned int fps = 30;  //�ʴ�30������
	int highscore = 0;      //�ְ� ����
	int oldscore = 0;


	while (true) {
		InitPlayer(&p);  //�÷��̾� �ʱ�ȭ
		InitMap(&m);     //�� �ʱ�ȭ
		tMainEnd = tMainStart = clock();

		//���ӽ���
		cls(BLACK, WHITE);
		while (keepGoing) {
			tMainStart = clock();
			//�����̽��� -> ���� �Է�
			if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !IsPlayerJumping(&p))
				Jump(&p);

			//������Ʈ(�÷��̾�, ��)
			UpdatePlayer(&p, ((float)(tMainStart - tMainEnd) * gamespeed) / 1000); //
			UpdateMap(&m, (int)p.real_x);

			//�ӵ� ����
			RunFaster(&p);

			//������ũ ���� Ȯ�� 2%
			if (rand() % 100 > 97)
				makespikes(&m);


			//�׸��� (��, �÷��̾�)
			RenderMap(&m);
			RenderPlayer(&p);

			//�ε����� �� �ְ� ���� ����
			if (IsPlayerSafe(&m, &p) == false) {
				keepGoing = false;
				highscore = SetHighscore(highscore, p.score);
				break;
			}

			//���� ���
			gotoxy(0, 1);
			p.score += (int)(tMainStart - tMainEnd / CLOCKS_PER_SEC) / 1000; //


			tMainEnd = clock();

			printf("���� %d\n", p.score);

			//�ְ� ���� ���
			gotoxy(80, 1);
			printf("�ְ����� %d\n", highscore);


			Sleep(fps);

			//�÷��̾� �����
			ErasePlayer(&p);

		}


		//�ε������� colideshape
		PrintColideShape(&p, keepGoing);


		//���� ���� ���
		PrintGameOver();

		//����� ���� �����
		keepGoing = IsRetry();

		//����� or ����
		if (keepGoing)
			continue;
		else
			break;
	}
}



//�ְ� ���� ���ϱ�
int SetHighscore(int highscore, int score) {
	if (highscore >= score)
		return highscore;
	else
		return score;
}

//����� ����
bool IsRetry() {
	unsigned char key_input;
	Sleep(1000);
	gotoxy(22, 20);
	textcolor(WHITE, BLACK);
	printf("Press R Button To Restart Game Or Press ESC To End\n");
	Sleep(2000);
	fflush(stdin);


input_Button:

	if (_kbhit())
		key_input = _getch();

	if (key_input == SmallR)
		return true;

	else if (key_input == ESC)
		return false;

	else
		goto input_Button;
}

//���� ���� ���
void PrintGameOver() {
	FILE *fp;
	char gameoverPrint[200];
	int i = 0;
	cls(WHITE, BLACK);
	fp = fopen("GAMEOVER.txt", "r");
	while (!feof(fp)) {
		textcolor(WHITE, CYAN1);
		fgets(gameoverPrint, 200, fp);
		gotoxy(0, i + 3);
		printf("%s", gameoverPrint);
		Sleep(90);//500
		i++;
	}
	fclose(fp);
}

//���� ����
void ExitGame() {
	exit(1);
}






/*------------------SYSTEM CONTROL----------------------*/

//�ܼ�â �̸�
void SetConsoleName() {
	system("title RunGame.exe");
}


//Ŀ���� �Ⱥ��̰� �Ѵ�
void RemoveCursor() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

//437�̸� ����ȯ��, 949�̸� �ѱ� ȯ��
//void changeLang() {
//   char cmd[100];
//   system("cls");
//   sprintf(cmd, "chcp 949"); //437
//   system(cmd);
//   system("cls");
//}

//��Ʈ, ��Ʈ ũ�� ����(�˻��ؼ� ã��)
void SetFont(const char *font, short fontsize) {
	CONSOLE_FONT_INFOEX cfi;
	size_t pcn;
	wchar_t *wc = (wchar_t*)malloc(sizeof(wchar_t)*(strlen(font) + 1));
	memset(wc, 0, sizeof(wchar_t)*(strlen(font) + 1));
	memset(&cfi, 0, sizeof(cfi));
	cfi.cbSize = sizeof(cfi);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);
	cfi.dwFontSize.X *= (fontsize / cfi.dwFontSize.Y);
	cfi.dwFontSize.Y = fontsize;
	mbstowcs_s(&pcn, wc, sizeof(wchar_t)*strlen(font), font, strlen(font));
	wcscpy_s(cfi.FaceName, sizeof(wchar_t)*strlen(font), wc);
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

//���� ���ϴ� ��ġ�� Ŀ�� �̵�
void gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}

//�ܼ�â ũ�� ����
void ControlWindowConsole() {
	char cmd[100];
	system("cls");
	sprintf(cmd, "mode con:cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);
}

//���ڻ� �� ���ڹ�� ��
void textcolor(int fg_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

//���� ���� (���� �� ��)
void SetColor(colorset *c)
{
	textcolor(c->tc, c->bgc);
}

//ȭ�� ����� ���ϴ� �������� �����Ѵ�.
void cls(int bg_color, int text_color) {
	char cmd[100] = { 0, };
	system("cls");
	if (bg_color > 0xf || text_color > 0xf)
		return;
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}