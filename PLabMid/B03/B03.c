#include <stdio.h>
#include <string.h>

int main() {
	int flag;
	int n;
	int sum;
	int len;
	int i;
	char buf[80];

	scanf("%d", &n);
	getchar();
	printf("\n");
	while (n--) {
		
		flag = 0;

		//산술방법
		sum = 0;
		gets(buf);
		len = strlen(buf);

		for (i = 0; i < len; ++i)
		{
			if ((buf[i] != '0') && (buf[i] != '1'))
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			printf("N/A\n");
			continue;
		}

		for (i = 0; i < len; ++i)
		{
			sum += buf[i] - '0';
			if (i < len - 1)
				sum *= 2;
		}

		printf("%X\n", sum);
	}
}