// 2015-1학기 프로그래밍랩 6주
// Lab6-3 구조체 선언과 입 출력
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 이름 찾기 위해 필요
typedef struct student {
	char name[20];
	int year;
	char no[20];
	char phone[20];
} Student;

void PrintStudent(Student *s)
{
	printf("이름:%s 학년:%d 학번:%s 전화:%s\n", s->name, s->year, s->no, s->phone);
}

/*
void InputStudent(Student *s)
{
	printf("이름 : "); scanf("%s", &(s->name));
	printf("학년 : "); scanf("%d", &(s->year));
	printf("학번 : "); scanf("%s", &(s->no));
	printf("전화 : "); scanf("%s", &(s->phone));
}*/

void InputStudent(FILE *fp, Student *s) {
	fscanf(fp, "%s", &(s->name));
	fscanf(fp, "%d", &(s->year));
	fscanf(fp, "%s", &(s->no));
	fscanf(fp, "%s", &(s->phone));
}

void main(void)
{
	int i, count, found;
	char name[20]; // 찾을 이름 입력 용
	Student *data;
	FILE *fp;
	fp = fopen("input.txt", "r");
	//printf("몇명 : ");
	fscanf(fp, "%d", &count);
	data = (Student *)malloc(sizeof(Student) * count); // 완성할것

	for (i = 0; i < count; i++) {
		// 입력 부분 완성
		//printf("\n자료번호 %d 입력\n", i + 1);
		InputStudent(fp, &data[i]); // 완성할것
	}
	fclose(fp);

	for (i = 0; i < count; i++) // 출력
		PrintStudent(&data[i]);

	while (1) {
		printf("찾을 이름: ");
		scanf("%s", name); // 이름 입력
		found = 0;
		if (strcmp(name, "end") == 0)
			break;
		for (i = 0; i < count; i++) { // 자료 찾기
			// 같은 이름을 찾아서 맞으면  break
			if (strcmp(data[i].name, name) == 0) // 찾으면 break
				break;
		}
		if (i < count) // 찾았다.
			PrintStudent(&data[i]);
		else
			printf("찾는 데이타가 없습니다.\n");
	}
}