#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char *str1; //���� ���ڿ�
	char *str2; //�� ���ڿ�
	char *usingstrstr;
	char *last;
	int i;
	int str2len;

	str1 = (char *)malloc(sizeof(char) * 100);
	str2 = (char *)malloc(sizeof(char) * 100);
	usingstrstr = (char *)malloc(sizeof(char) * 100);
	last = (char *)malloc(sizeof(char) * 100);

	printf("���ڿ��Է� : ");
	gets(str1);

	while (strlen(str1))
	{
		i = 0;

		printf("���繮�ڿ� : %s\n", str1);

		printf("  �����ڿ� : ");
		gets(str2);

		usingstrstr = strstr(str1, str2);
		
		//���� ���ڿ��� ���� ��
		if (usingstrstr == NULL)
		{
			printf("���� ���ڿ��� �����ϴ�.\n");
			continue;
		}
		
		str2len = strlen(str2);

		while (i != (strlen(usingstrstr) - str2len)) //str2 �޺κ��� last�� ����
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