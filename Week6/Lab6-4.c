// 2017-1학기 프로그래밍랩 6주
// Lab6-4 문자열 처리
#include <stdio.h>
#include <string.h>
void reverse(char to[], char from[])
{
	int i;
	for (i = 0; i < strlen(from); i++)
		to[i] = from[strlen(from) - i - 1];
	to[i] = '\0';
	// 완성할것
}

// 한글을 고려한 reverse
void reverseK(char to[], char from[])
{
	// 한글 2bytes를 고려한 reverse
	int i;

	for (i = 0; i < strlen(from); i++) {

		if ((unsigned char)from[i] >= 0x80 && (unsigned char)from[i + 1] >= 0x80)
		{
			for (i = 0; i < strlen(from); i += 2) {
				to[i] = from[strlen(from) - i-2];
				to[i + 1] = from[strlen(from) - i - 1];
			}
			break;
		}

		to[i] = from[strlen(from) - i - 1];
	}

	to[i] = '\0';
}

void main()
{
	char str1[100] = "Hansung";
	char str2[100] = "University";
	char str3[100] = "Computer";
	char str4[100] = "Engineering";
	char str5[100];
	char str6[100];
	char str7[100] = "홍길동";
	int ret;

	ret = strlen(str1);
	printf("strlen(%s)=%d\n", str1, ret);
	ret = strcmp(str1, str1);
	printf("strcmp(%s, %s) = %d\n", str1, str1, ret);
	ret = strcmp(str1, str2);
	printf("strcmp(%s, %s) = %d\n", str1, str2, ret);
	ret = strcmp(str1, str3);
	printf("strcmp(%s, %s) = %d\n", str1, str3, ret);

	strcpy(str5, str1);
	printf("strcpy str5 = %s\n", str5);
	strcat(str5, " ");
	strcat(str5, str2);
	printf("strcat str5, str2 = %s\n", str5);

	reverse(str6, str5);
	printf("reverse str5 = %s\n", str6);

	reverse(str6, str7);
	printf("reverse str7 = %s\n", str7);

}

