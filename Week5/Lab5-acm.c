// 2017�� 1�б� ���α׷��ַ�
// 5�� ACM ����
// VPS (Valid Parantesis String) ����
// () �� ¦�� ������ YES, Ʋ���� NO
#include <stdio.h>
void main()
{
	int ntest;
	char buf[100];
	int i;
	int count1, count2;
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%s", buf); // 1���� �Է�
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
			// ���ڿ��� ��� �˻��ؼ�
			// ( ������ ) ������ count�ϰ�
			// count1 count2 �� ���Ͽ� �Ǵ�
	}
}