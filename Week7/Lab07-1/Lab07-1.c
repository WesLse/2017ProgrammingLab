// 2017년 1학기 프로그래밍랩 - 12주
// Lab12-1 파일 입/출력

#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	char ch;
	char filename[100];
	char buf[100];
	int id = 1492001;
	char *name = "홍길동";
	char *phone = "010-1234-5678";

	char *name1;
	char *phone1;
	int id1;
	name1 = (char *)malloc(sizeof(char)*20);
	phone1 = (char *)malloc(sizeof(char) * 20);
	fp = fopen("data.txt", "w"); // 파일명을 입력 받는다면?
	//fp = fopen(stdin, "w");
	//scanf("%d %s %s", &id1, name1, phone1); // 키보드에 입력 받아 저장하는 경우
	//키보드로 입력 받는 경우 배열이 초기화되어 있으면 const라서 오류

	fprintf(fp,"%d\n", id);
	fprintf(fp,"%s\n", name);
	fprintf(fp,"%s\n", phone);
	fclose(fp);

	printf("입력 파일 명 : ");
	scanf("%s", filename);
	fp = fopen(filename, "r");
	fscanf(fp, "%d", &id);
	printf("학번=%d\n", id);
	fscanf(fp, "%s", buf);
	printf("이름=%s\n", buf);
	fscanf(fp, "%s", buf);
	printf("전화=%s\n", buf);
	fclose(fp);
}