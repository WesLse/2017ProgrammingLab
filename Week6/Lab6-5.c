// 2017-1�б� ���α׷��ַ� 6��
// Lab6-5 ���ڿ� ó��
// string �Լ��� ��� mystrcpy() ������ ����
// reverse() �Լ��� �ѱ��� ����Ͽ��� ��
//
#include <stdio.h>
#include <string.h>
char *mystrcpy(char *to, char *from)
{
	int i;
	for (i = 0; i < mystrlen(from); i++)
		to[i] = from[i];
	to[i] = '\0';
	return to;
}
int mystrlen(char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}
int mystrcmp(char *s1, char *s2)
{
	int i, count = 0;
	for (i = 0; i < mystrlen(s1); i++) {
		if (s1[i] > s2[i]) {
			count = 1;
			break;
		}
		else if (s1[i] < s2[i]) {
			count = -1;
			break;
		}
	}
	return count;
}
char *mystrcat(char *to, char *from)
{
	int i;
	int tolength = mystrlen(to);
	for (i = 0; i < mystrlen(from); i++)
		to[tolength + i] = from[i];
	to[tolength + i] = '\0';

	return to;
}
// �ѱ��� ����� reverse �ۼ�
void reverse(char *to, char *from)
{
	int i;
	for (i = 0; i < mystrlen(from); ) {

		if ((unsigned char)from[mystrlen(from) - i - 2] >= 0x80 && (unsigned char)from[mystrlen(from) - i - 1] >= 0x80)
		{
			to[i] = from[mystrlen(from) - i - 2];
			to[i + 1] = from[mystrlen(from) - i - 1];
			i += 2;
		}

		else {
			to[i] = from[mystrlen(from) - i - 1];
			i++;
		}
	}

	to[i] = '\0';
}
void main()
{
	char str1[100] = "�Ѽ����б�";
	char str2[100] = "University";
	char str3[100] = "Computer";
	char str4[100] = "Engineering";
	char str5[100];
	char str6[100];
	int ret;

	ret = mystrlen(str1);
	printf("mystrlen(%s)=%d\n", str1, ret);
	ret = mystrcmp(str1, str1);
	printf("mystrcmp(%s, %s) = %d\n", str1, str1, ret);
	ret = mystrcmp(str1, str2);
	printf("mystrcmp(%s, %s) = %d\n", str1, str2, ret);
	ret = mystrcmp(str1, str3);
	printf("mystrcmp(%s, %s) = %d\n", str1, str3, ret);
	mystrcpy(str5, str1);
	printf("mystrcpy str5 = %s\n", str5);
	mystrcat(str5, " ");
	mystrcat(str5, str2);
	printf("mystcat str5 = %s\n", str5);
	reverse(str6, str5);
	printf("reverse str5 = %s\n", str6);
}
