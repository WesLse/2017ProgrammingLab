#include <stdio.h>

int main()
{
	char name[7];
	int i;

	printf("�ֹι�ȣ ���ڸ� : "); 
	gets(name);

	if (name[2] == '0')
	{
		if (name[4] == '0')
			printf("19%c%c�� %c�� %c�ϻ��Դϴ�.\n", name[0], name[1], name[3], name[5]);
		else
			printf("19%c%c�� %c�� %c%c�ϻ��Դϴ�.\n", name[0], name[1], name[3], name[4], name[5]);
	}
	else
	{
		if (name[4] == '0')
			printf("19%c%c�� %c%c�� %c�ϻ��Դϴ�.\n", name[0], name[1], name[2], name[3], name[5]);
		else
			printf("19%c%c�� %c%c�� %c%c�ϻ��Դϴ�.\n", name[0], name[1], name[2], name[3], name[4], name[5]);
	}

	return 0;
}