// 2017�� 1�б� ���α׷��ַ� - 12��
// Lab12-1 ���� ��/���

#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	char ch;
	char filename[100];
	char buf[100];
	int id = 1492001;
	char *name = "ȫ�浿";
	char *phone = "010-1234-5678";

	char *name1;
	char *phone1;
	int id1;
	name1 = (char *)malloc(sizeof(char)*20);
	phone1 = (char *)malloc(sizeof(char) * 20);
	fp = fopen("data.txt", "w"); // ���ϸ��� �Է� �޴´ٸ�?
	//fp = fopen(stdin, "w");
	//scanf("%d %s %s", &id1, name1, phone1); // Ű���忡 �Է� �޾� �����ϴ� ���
	//Ű����� �Է� �޴� ��� �迭�� �ʱ�ȭ�Ǿ� ������ const�� ����

	fprintf(fp,"%d\n", id);
	fprintf(fp,"%s\n", name);
	fprintf(fp,"%s\n", phone);
	fclose(fp);

	printf("�Է� ���� �� : ");
	scanf("%s", filename);
	fp = fopen(filename, "r");
	fscanf(fp, "%d", &id);
	printf("�й�=%d\n", id);
	fscanf(fp, "%s", buf);
	printf("�̸�=%s\n", buf);
	fscanf(fp, "%s", buf);
	printf("��ȭ=%s\n", buf);
	fclose(fp);
}