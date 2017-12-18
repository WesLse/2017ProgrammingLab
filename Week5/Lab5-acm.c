// 2017년 1학기 프로그래밍랩
// 5주 ACM 문제
// VPS (Valid Parantesis String) 검증
// () 의 짝이 맞으면 YES, 틀리면 NO
#include <stdio.h>
void main()
{
	int ntest;
	char buf[100];
	int i;
	int count1, count2;
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%s", buf); // 1라인 입력
		count1 = count2 = 0;
		for (i = 0; i < sizeof(buf); i++) {
			if (buf[i] == '(')
				count1++;
			else if (buf[i] == ')')
				count2++;
		}
		if (count1 == count2)
			printf("YES\n");
		else if (count1 != count2)
			printf("NO\n");
			// 문자열을 모두 검사해서
			// ( 갯수와 ) 갯수를 count하고
			// count1 count2 를 비교하여 판단
	}
}