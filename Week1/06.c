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

	//(1)�Է� scanf()���
	printf("(1) �Է� str1 : "); scanf("%s", str1);
	printf("    �Է� str2 : "); scanf("%s", str2);
	//(2)��ȯ �� ���
	strcpy(temp, str1); strcpy(str1, str2); strcpy(str2, temp);
	printf("(2) ��ȯ str1=%s str2=%s\nlen1=%d len2=%d\n", str1, str2, strlen(str1), strlen(str2));
	//(3)���� �� ���
	strcpy(str3, str2); printf("(3) ���� str3 = %s\n", str3);
	//(4)�̾���̱� �� ���
	strcat(str3, " "); strcat(str3, str1); strcat(str3, " Computer Engineering");
	printf("(4) �̾� ���̱� str3=%s\nlen3=%d\n", str3, strlen(str3));
	//(5) ������ reverse(str4, str3) �� str4 ���
	reverse(str4, str3);
	printf("(5) ������ str4=%s\nlen4=%d\n", str4, strlen(str4));

	return 0;
}