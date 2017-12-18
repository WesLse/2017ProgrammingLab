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
#define DELETED	"DELETED" // record 가 삭제되었다는 표시

void displaymenu()
{
	printf("\n*** 전호번호 ***\n");
	printf("(1) 목록\n");
	printf("(2) 검색\n");
	printf("(3) 추가\n");
	printf("(4) 변경\n");
	printf("(5) 삭제\n");
	printf("(99) 종료\n");
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

	printf("\n** 전체 목록 **\n");
	ndata = getnumberofdata(fp);
	if (ndata==0) {
		printf("데이타가 없습니다.\n");
		return;
	}
	fseek(fp, 0, SEEK_SET); // 처음으로 이동
	while (ndata--) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, DELETED)==0 &&
				strcmp(data.phone, DELETED)==0)
			continue;
		disp_one(&data);
	}
}

// 찾아서 display 하고 record 번호를 return
int search(FILE *fp)
{
	Phone data;
	char name[20]; // 찾을 이름
	int n;
	int ndata; // 전체 data 수

	printf("\n** 자료 찾기 **\n");
	ndata = getnumberofdata(fp); //record number
	if (ndata == 0) {
		printf("Data가 없습니다.\n");
		return -1;
	}

	printf("찾을이름 : ");
	scanf("%s", name);

	fseek(fp, 0, SEEK_SET); // 처음으로 이동
	for (n=0;n<ndata;n++) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, DELETED)==0 &&
				strcmp(data.phone, DELETED)==0)
				continue;
		if (strcmp(data.name, name)==0)
			break;
	}
	if (n>=ndata) {
		printf("찾는 데이타가 없습니다.\n");
		return -1;
	}
	disp_one(&data);
	return n;
}

void inputone(Phone *data)
{

}

// 비어있는 record 를 찾는다 찾으면 그 record 번호를,
// 없으면 -1로 return
int getblank(FILE *fp)
{
}

// 데이타 추가
void add(FILE *fp)
{
	printf("\n** 추가 **\n");
	// Lab12-4 방법을 변경하여야 함.
	// 무조건 뒤에 추가하는 것이 아니고,
	// 빈 slot을 찾아서 있으면 그 slot에 쓰고
	// 빈 slot이 없으면 끝으로 이동해서 append 한다.
}

// 데이타 변경하기
void updateone(FILE *fp, int n)
{
	printf("\n** 변경 **\n");
	// n 은 변경할 record 번호, n==-1이면 아직 검색이 되지 않은 상태임.
	if (n == -1) {
		printf("변경할 데이타 검색을 먼저하세요.!\n");
		return;
	}
}

// 데이터 삭제하기
void deleteone(FILE *fp, int n)
{
	Phone deletedata = {DELETED, DELETED}; // 삭제 되었다는 표시
	Phone data;
	int ans;
	int ndata;

	printf("\n** 삭제 **\n");
	// 삭제할 번호 = n, 검색에서 나온값.
	// n == -1이라면 검색을 먼저 하라고 안내한다.
	if (n == -1) {
		printf("삭제할 데이타 검색을 먼저하세요.!\n");
		return;
	}

}
void main()
{
	//Phone data;
	FILE *fp;
	//int i;
	int record_number; // 현재 찾은 record 번호
	int menu;

	record_number = -1; // 변경/삭제 대상 record 번호

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
		} while (menu!=99 && (menu<1 || menu>5));
		if (menu==99) // 종료
			break;
		switch(menu) {
		case 1: list(fp);
			break;
		case 2: record_number = search(fp);
			break;
		case 3: add(fp);
			record_number = -1;
			break;
		case 4: updateone(fp, record_number);
			record_number = -1;
			break;
		case 5: deleteone(fp, record_number);
			record_number = -1;
			break;
		}
	}

	fclose(fp);
}
