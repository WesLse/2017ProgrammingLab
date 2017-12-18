// 2017 프로그래밍랩 12주
// Lab12-4 파일을 이용한 전화번호 관리
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phone {
	char name[20];
	char phone[20];
} Phone;

#define FILENAME "phone.txt"

void displaymenu()
{
	printf("\n*** 전호번호 ***\n");
	printf("(1) 목록\n");
	printf("(2) 검색\n");
	printf("(3) 추가\n");
	printf("(4) 종료\n");
	printf("---------------\n");
	printf("선택하세요 : ");
}

// 파일에 몇개의 데이타가 있는지 계산
// data 수 = file 크기 / 구조체크기
// file 크기 구하기 file 끝에서 ftell(fp) / sizeof(Phone)
int getnumberofdata(FILE *fp)
{
	int filesize;
	int n;
	fseek(fp, 0, SEEK_END); // 끝으로 이동
	filesize = ftell(fp); // 파일 크기가 return 됨
	n = filesize / sizeof(Phone);
	return n;

}

// data 하나를 display 
void disp_one(Phone *data)
{
	printf("이름: %s   전화: %s\n", data->name, data->phone);
}

// 전체 데이타 list
void list(FILE *fp)
{
	Phone data;
	int ndata;

	printf("\n** 자료 목록 **\n");
	ndata = getnumberofdata(fp);
	if (ndata==0) {
		printf("데이타가 없습니다.\n");
		return;
	}
	fseek(fp, 0, SEEK_SET); // 처음으로 이동
	while (ndata--) {
		fread(&data, sizeof(data), 1, fp);
		disp_one(&data);
	}
}
void search(FILE *fp)
{
	Phone data;
	char name[20]; // 찾을 이름
	int n;
	int ndata; // 전체 data 수

	printf("\n** 자료 찾기 **\n");
	ndata = getnumberofdata(fp); //record number
	if (ndata == 0) {
		printf("Data가 없습니다.\n");
		return;
	}

	printf("찾을이름 : ");
	scanf("%s", name);

	fseek(fp, 0, SEEK_SET); // 처음으로 이동
	for (n=0;n<ndata;n++) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name)==0)
			break;
	}
	if (n>=ndata) {
		printf("찾는 데이타가 없습니다.\n");
		return;
	}
	disp_one(&data);
}

// 데이타 추가
void add(FILE *fp)
{
	Phone data;
	printf("\n** 자료 추가 **\n");
	printf("이름 : ");
	scanf("%s", data.name);
	printf("전화번호 : ");
	scanf("%s", data.phone);
	fseek(fp, 0, SEEK_END); // 끝으로 이동
	fwrite(&data, sizeof(data), 1, fp);
}

void main()
{
	//Phone data;
	FILE *fp;
	//int i;
	int menu;

	// 파일을 open, 새로운 파일이면 w로 생성
	if ((fp = fopen(FILENAME, "r+b"))==NULL) { // 파일이 없으면
		fp = fopen(FILENAME, "w+b"); // 새로 생성
		if (fp==NULL) {
			printf("파일을 열 수 없습니다.\n");
			exit(0);
		}
	}

	while (1) {
		do {
			displaymenu();
			scanf("%d", &menu);
		} while (menu<1 || menu>4);
		if (menu==4) // 종료
			break;
		switch(menu) {
		case 1: list(fp);
			break;
		case 2: search(fp);
			break;
		case 3: add(fp);
			break;
		}
	}

	fclose(fp);
}
