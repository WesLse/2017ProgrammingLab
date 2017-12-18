// 2015-1�б� ���α׷��ַ� 6��
// Lab6-3 ����ü ����� �� ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // �̸� ã�� ���� �ʿ�
typedef struct student {
	char name[20];
	int year;
	char no[20];
	char phone[20];
} Student;

void PrintStudent(Student *s)
{
	printf("�̸�:%s �г�:%d �й�:%s ��ȭ:%s\n", s->name, s->year, s->no, s->phone);
}

/*
void InputStudent(Student *s)
{
	printf("�̸� : "); scanf("%s", &(s->name));
	printf("�г� : "); scanf("%d", &(s->year));
	printf("�й� : "); scanf("%s", &(s->no));
	printf("��ȭ : "); scanf("%s", &(s->phone));
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
	char name[20]; // ã�� �̸� �Է� ��
	Student *data;
	FILE *fp;
	fp = fopen("input.txt", "r");
	//printf("��� : ");
	fscanf(fp, "%d", &count);
	data = (Student *)malloc(sizeof(Student) * count); // �ϼ��Ұ�

	for (i = 0; i < count; i++) {
		// �Է� �κ� �ϼ�
		//printf("\n�ڷ��ȣ %d �Է�\n", i + 1);
		InputStudent(fp, &data[i]); // �ϼ��Ұ�
	}
	fclose(fp);

	for (i = 0; i < count; i++) // ���
		PrintStudent(&data[i]);

	while (1) {
		printf("ã�� �̸�: ");
		scanf("%s", name); // �̸� �Է�
		found = 0;
		if (strcmp(name, "end") == 0)
			break;
		for (i = 0; i < count; i++) { // �ڷ� ã��
			// ���� �̸��� ã�Ƽ� ������  break
			if (strcmp(data[i].name, name) == 0) // ã���� break
				break;
		}
		if (i < count) // ã�Ҵ�.
			PrintStudent(&data[i]);
		else
			printf("ã�� ����Ÿ�� �����ϴ�.\n");
	}
}