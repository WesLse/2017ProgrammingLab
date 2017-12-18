#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char *str1; //현재 문자열
	char *str2; //뺄 문자열
	char *usingstrstr;
	char *last;
	int i;
	int str2len;

	str1 = (char *)malloc(sizeof(char) * 100);
	str2 = (char *)malloc(sizeof(char) * 100);
	usingstrstr = (char *)malloc(sizeof(char) * 100);
	last = (char *)malloc(sizeof(char) * 100);

	printf("문자열입력 : ");
	gets(str1);

	while (strlen(str1))
	{
		i = 0;

		printf("현재문자열 : %s\n", str1);

		printf("  뺄문자열 : ");
		gets(str2);

		usingstrstr = strstr(str1, str2);
		
		//같은 문자열이 없을 때
		if (usingstrstr == NULL)
		{
			printf("같은 문자열이 없습니다.\n");
			continue;
		}
		
		str2len = strlen(str2);

		while (i != (strlen(usingstrstr) - str2len)) //str2 뒷부분을 last에 저장
		{
			last[i] = usingstrstr[str2len + i];
			++i;
		}
		last[i] = '\0';

		*usingstrstr = '\0';

		strcat(str1, last);
	}

	free(str1);
	free(str2);
	free(last);
}