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
#define DELETED	"DELETED" // record �� �����Ǿ��ٴ� ǥ��

void displaymenu()
{
	printf("\n*** ��ȣ��ȣ ***\n");
	printf("(1) ���\n");
	printf("(2) �˻�\n");
	printf("(3) �߰�\n");
	printf("(4) ����\n");
	printf("(5) ����\n");
	printf("(99) ����\n");
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

	printf("\n** ��ü ��� **\n");
	ndata = getnumberofdata(fp);
	if (ndata==0) {
		printf("����Ÿ�� �����ϴ�.\n");
		return;
	}
	fseek(fp, 0, SEEK_SET); // ó������ �̵�
	while (ndata--) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, DELETED)==0 &&
				strcmp(data.phone, DELETED)==0)
			continue;
		disp_one(&data);
	}
}

// ã�Ƽ� display �ϰ� record ��ȣ�� return
int search(FILE *fp)
{
	Phone data;
	char name[20]; // ã�� �̸�
	int n;
	int ndata; // ��ü data ��

	printf("\n** �ڷ� ã�� **\n");
	ndata = getnumberofdata(fp); //record number
	if (ndata == 0) {
		printf("Data�� �����ϴ�.\n");
		return -1;
	}

	printf("ã���̸� : ");
	scanf("%s", name);

	fseek(fp, 0, SEEK_SET); // ó������ �̵�
	for (n=0;n<ndata;n++) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, DELETED)==0 &&
				strcmp(data.phone, DELETED)==0)
				continue;
		if (strcmp(data.name, name)==0)
			break;
	}
	if (n>=ndata) {
		printf("ã�� ����Ÿ�� �����ϴ�.\n");
		return -1;
	}
	disp_one(&data);
	return n;
}

void inputone(Phone *data)
{

}

// ����ִ� record �� ã�´� ã���� �� record ��ȣ��,
// ������ -1�� return
int getblank(FILE *fp)
{
}

// ����Ÿ �߰�
void add(FILE *fp)
{
	printf("\n** �߰� **\n");
	// Lab12-4 ����� �����Ͽ��� ��.
	// ������ �ڿ� �߰��ϴ� ���� �ƴϰ�,
	// �� slot�� ã�Ƽ� ������ �� slot�� ����
	// �� slot�� ������ ������ �̵��ؼ� append �Ѵ�.
}

// ����Ÿ �����ϱ�
void updateone(FILE *fp, int n)
{
	printf("\n** ���� **\n");
	// n �� ������ record ��ȣ, n==-1�̸� ���� �˻��� ���� ���� ������.
	if (n == -1) {
		printf("������ ����Ÿ �˻��� �����ϼ���.!\n");
		return;
	}
}

// ������ �����ϱ�
void deleteone(FILE *fp, int n)
{
	Phone deletedata = {DELETED, DELETED}; // ���� �Ǿ��ٴ� ǥ��
	Phone data;
	int ans;
	int ndata;

	printf("\n** ���� **\n");
	// ������ ��ȣ = n, �˻����� ���°�.
	// n == -1�̶�� �˻��� ���� �϶�� �ȳ��Ѵ�.
	if (n == -1) {
		printf("������ ����Ÿ �˻��� �����ϼ���.!\n");
		return;
	}

}
void main()
{
	//Phone data;
	FILE *fp;
	//int i;
	int record_number; // ���� ã�� record ��ȣ
	int menu;

	record_number = -1; // ����/���� ��� record ��ȣ

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
		} while (menu!=99 && (menu<1 || menu>5));
		if (menu==99) // ����
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
