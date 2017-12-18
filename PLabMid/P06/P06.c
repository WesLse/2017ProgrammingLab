#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
	char password[13];  //비밀번호
	char rightpw[13];   //재입력한 비밀번호
	int allAlpha, allDigit;
	int flag = 1, notSame = 0; //flag는 전체 루프를 돌게함 0이면 종료, notSame은 재입력한 비밀번호와 동치인지 확인
	int i, length;
	printf("비밀번호를 등록합니다.\n");
	while (flag) {
		allAlpha = 0;
		allDigit = 0;
		notSame = 0;

		printf("비밀번호는 영문, 숫자 포함 최소한 8자리 최대 12자리이어야 합니다.\n");
		printf("새로운 비밀번호 입력 : ");
		gets(password);

		length = strlen(password);

		//길이가 안맞으면 다시
		if (length < 8 || length > 13)
			continue;

		//알파벳이나 숫자가 없으면 다시
		for (i = 0; i < length; i++)
			if ((isalpha(password[i]) != 1) || (isdigit(password[i]) != 1))
				continue;

		//모두 알파벳이면 다시
		for (i = 0; i < length; ++i)
		{
			if (isalpha(password[i]))
				allAlpha++;
		}
		if (allAlpha == length)
			continue;

		//모두 숫자면 다시
		for (i = 0; i < length; ++i)
		{
			if (isdigit(password[i]))
				allDigit++;
		}
		if (allDigit == length)
			continue;

		//비밀번호 재입력
		printf("비밀번호 한번더 입력 : ");
		gets(rightpw);
		
		//틀리면
		for (i = 0; i < length; i++) {
			if (password[i] != rightpw[i])
			{
				printf("비밀번호를 정확히 입력하세요.\n");
				notSame = 1;
				break;
			}
		}
		//틀리면 다시
		if (notSame)
			continue;

		flag = 0;
	}
	printf("비밀번호가 등록되었습니다.\n");
}

