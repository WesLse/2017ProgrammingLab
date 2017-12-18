#include <stdio.h>
#include <string.h>

void reverse(char str4[], char str3[]) {

	int i = 0;
	while (i != strlen(str3)) {	
		str4[i] = str3[strlen(str3) - i - 1];
		i++;
	}
	str4[strlen(str3)] = '\0';
}

int main() {
	char str1[100];
	char str2[100];
	char str3[100];
	char str4[100];
	char temp[100];
	int len1, len2, len3, len4;

	//(1)입력 scanf()사용
	printf("(1) 입력 str1 : "); scanf("%s", str1);
	printf("    입력 str2 : "); scanf("%s", str2);
	//(2)교환 후 출력
	strcpy(temp, str1); strcpy(str1, str2); strcpy(str2, temp);
	printf("(2) 교환 str1=%s str2=%s\nlen1=%d len2=%d\n", str1, str2, strlen(str1), strlen(str2));
	//(3)복사 후 출력
	strcpy(str3, str2); printf("(3) 복사 str3 = %s\n", str3);
	//(4)이어붙이기 후 출력
	strcat(str3, " "); strcat(str3, str1); strcat(str3, " Computer Engineering");
	printf("(4) 이어 붙이기 str3=%s\nlen3=%d\n", str3, strlen(str3));
	//(5) 뒤집기 reverse(str4, str3) 후 str4 출력
	reverse(str4, str3);
	printf("(5) 뒤집기 str4=%s\nlen4=%d\n", str4, strlen(str4));

	return 0;
}