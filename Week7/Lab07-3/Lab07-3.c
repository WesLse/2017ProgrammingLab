// 2017 ���α׷��ַ� 12��
// Lab12-3 Random Access ����
#include <stdio.h>
typedef struct Student {
	int id;
	char name[20];
	char phone[20];
};
void main()
{
	struct Student data;
	FILE *fp;
	int i;
	fp = fopen("data.txt", "wb");
	for (i=0;i<5;i++) {
		scanf("%d %s %s", &data.id, data.name, data.phone);
		// fwrite( ,fp);
	}
	fclose(fp);

	fp = fopen("data.txt", "rb");
	while (1) {
		printf("����Ÿ��ȣ : ");
		scanf("%d", &i);
		if (i==99)
			break;
		// fseek(fp,  );
		// fread( ,fp);
		printf("�й�=%d\n",data.id);
		printf("�̸�=%s\n", data.name);
		printf("��ȭ=%s\n", data.phone);
	}
	fclose(fp);
}
