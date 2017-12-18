// 2017 프로그래밍랩 12주
// Lab12-2 구조체 저장 fread/fwrite
#include <stdio.h>
typedef struct Student {
	int id;
	char name[20];
	char phone[20];
};
void main()
{
	struct Student data = { 1493002, "홍길동", "010-1234-5678" };
	FILE *fp;
	fp = fopen("data.txt", "w+b");
	fwrite(&data, sizeof(data), 1, fp);
	fclose(fp);

	fp = fopen("data.txt", "r+b");
	fread(&data, sizeof(data), 1, fp);
	printf("학번=%d\n", data.id);
	printf("이름=%s\n", data.name);
	printf("전화=%s\n", data.phone);
	fclose(fp);
}
