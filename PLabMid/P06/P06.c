#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
	char password[13];  //��й�ȣ
	char rightpw[13];   //���Է��� ��й�ȣ
	int allAlpha, allDigit;
	int flag = 1, notSame = 0; //flag�� ��ü ������ ������ 0�̸� ����, notSame�� ���Է��� ��й�ȣ�� ��ġ���� Ȯ��
	int i, length;
	printf("��й�ȣ�� ����մϴ�.\n");
	while (flag) {
		allAlpha = 0;
		allDigit = 0;
		notSame = 0;

		printf("��й�ȣ�� ����, ���� ���� �ּ��� 8�ڸ� �ִ� 12�ڸ��̾�� �մϴ�.\n");
		printf("���ο� ��й�ȣ �Է� : ");
		gets(password);

		length = strlen(password);

		//���̰� �ȸ����� �ٽ�
		if (length < 8 || length > 13)
			continue;

		//���ĺ��̳� ���ڰ� ������ �ٽ�
		for (i = 0; i < length; i++)
			if ((isalpha(password[i]) != 1) || (isdigit(password[i]) != 1))
				continue;

		//��� ���ĺ��̸� �ٽ�
		for (i = 0; i < length; ++i)
		{
			if (isalpha(password[i]))
				allAlpha++;
		}
		if (allAlpha == length)
			continue;

		//��� ���ڸ� �ٽ�
		for (i = 0; i < length; ++i)
		{
			if (isdigit(password[i]))
				allDigit++;
		}
		if (allDigit == length)
			continue;

		//��й�ȣ ���Է�
		printf("��й�ȣ �ѹ��� �Է� : ");
		gets(rightpw);
		
		//Ʋ����
		for (i = 0; i < length; i++) {
			if (password[i] != rightpw[i])
			{
				printf("��й�ȣ�� ��Ȯ�� �Է��ϼ���.\n");
				notSame = 1;
				break;
			}
		}
		//Ʋ���� �ٽ�
		if (notSame)
			continue;

		flag = 0;
	}
	printf("��й�ȣ�� ��ϵǾ����ϴ�.\n");
}

