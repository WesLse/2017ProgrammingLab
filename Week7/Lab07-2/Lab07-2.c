// 2017 ���α׷��ַ� 12��
// Lab12-2 ����ü ���� fread/fwrite
#include <stdio.h>
typedef struct Student {
	int id;
	char name[20];
	char phone[20];
};
void main()
{
	struct Student data = { 1493002, "ȫ�浿", "010-1234-5678" };
	FILE *fp;
	fp = fopen("data.txt", "w+b");
	fwrite(&data, sizeof(data), 1, fp);
	fclose(fp);

	fp = fopen("data.txt", "r+b");
	fread(&data, sizeof(data), 1, fp);
	printf("�й�=%d\n", data.id);
	printf("�̸�=%s\n", data.name);
	printf("��ȭ=%s\n", data.phone);
	fclose(fp);
}
