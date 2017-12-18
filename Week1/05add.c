#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main()
{
	char name1[14];
	int name2[14];
	int i;
	int right;//참 거짓

	printf("주민번호 13자리(-없이) : ");
	gets(name1);

	for (i = 0; i < 13; i++)
	{
		name2[i] = (int)name1[i] - '0';
	}

	if (name2[12] == (11 - ((2 * name2[0] + 3 * name2[1] + 4 * name2[2] + 5 * name2[3]
		+ 6 * name2[4] + 7 * name2[5] + 8 * name2[6] + 9 * name2[7] + 2 * name2[8] +
		3 * name2[9] + 4 * name2[10] + 5 * name2[11]) % 11)) % 10)
		right = TRUE;
	else
		right = FALSE;
	
	//판정

	if (right == TRUE) {
	
		printf("올바른 주민등록번호입니다.\n");

		if (name1[2] == '0')
		{
			if (name1[4] == '0')
				printf("19%c%c년 %c월 %c일생입니다.\n", name1[0], name1[1], name1[3], name1[5]);
			else
				printf("19%c%c년 %c월 %c%c일생입니다.\n", name1[0], name1[1], name1[3], name1[4], name1[5]);
		}
		else
		{
			if (name1[4] == '0')
				printf("19%c%c년 %c%c월 %c일생입니다.\n", name1[0], name1[1], name1[2], name1[3], name1[5]);
			else
				printf("19%c%c년 %c%c월 %c%c일생입니다.\n", name1[0], name1[1], name1[2], name1[3], name1[4], name1[5]);
		}
	}
	else
		printf("잘못된 주민등록번호입니다.\n");
	
	return 0;
}