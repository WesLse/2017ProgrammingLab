// 2017 ���α׷��ַ� 12��
// Lab12-4 ������ �̿��� ��ȭ��ȣ ����
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
	printf("\n*** ��ȣ��ȣ ***\n");
	printf("(1) ���\n");
	printf("(2) �˻�\n");
	printf("(3) �߰�\n");
	printf("(4) ����\n");
	printf("---------------\n");
	printf("�����ϼ��� : ");
}

// ���Ͽ� ��� ����Ÿ�� �ִ��� ���
// data �� = file ũ�� / ����üũ��
// file ũ�� ���ϱ� file ������ ftell(fp) / sizeof(Phone)
int getnumberofdata(FILE *fp)
{
	int filesize;
	int n;
	fseek(fp, 0, SEEK_END); // ������ �̵�
	filesize = ftell(fp); // ���� ũ�Ⱑ return ��
	n = filesize / sizeof(Phone);
	return n;

}

// data �ϳ��� display 
void disp_one(Phone *data)
{
	printf("�̸�: %s   ��ȭ: %s\n", data->name, data->phone);
}

// ��ü ����Ÿ list
void list(FILE *fp)
{
	Phone data;
	int ndata;

	printf("\n** �ڷ� ��� **\n");
	ndata = getnumberofdata(fp);
	if (ndata==0) {
		printf("����Ÿ�� �����ϴ�.\n");
		return;
	}
	fseek(fp, 0, SEEK_SET); // ó������ �̵�
	while (ndata--) {
		fread(&data, sizeof(data), 1, fp);
		disp_one(&data);
	}
}
void search(FILE *fp)
{
	Phone data;
	char name[20]; // ã�� �̸�
	int n;
	int ndata; // ��ü data ��

	printf("\n** �ڷ� ã�� **\n");
	ndata = getnumberofdata(fp); //record number
	if (ndata == 0) {
		printf("Data�� �����ϴ�.\n");
		return;
	}

	printf("ã���̸� : ");
	scanf("%s", name);

	fseek(fp, 0, SEEK_SET); // ó������ �̵�
	for (n=0;n<ndata;n++) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name)==0)
			break;
	}
	if (n>=ndata) {
		printf("ã�� ����Ÿ�� �����ϴ�.\n");
		return;
	}
	disp_one(&data);
}

// ����Ÿ �߰�
void add(FILE *fp)
{
	Phone data;
	printf("\n** �ڷ� �߰� **\n");
	printf("�̸� : ");
	scanf("%s", data.name);
	printf("��ȭ��ȣ : ");
	scanf("%s", data.phone);
	fseek(fp, 0, SEEK_END); // ������ �̵�
	fwrite(&data, sizeof(data), 1, fp);
}

void main()
{
	//Phone data;
	FILE *fp;
	//int i;
	int menu;

	// ������ open, ���ο� �����̸� w�� ����
	if ((fp = fopen(FILENAME, "r+b"))==NULL) { // ������ ������
		fp = fopen(FILENAME, "w+b"); // ���� ����
		if (fp==NULL) {
			printf("������ �� �� �����ϴ�.\n");
			exit(0);
		}
	}

	while (1) {
		do {
			displaymenu();
			scanf("%d", &menu);
		} while (menu<1 || menu>4);
		if (menu==4) // ����
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
