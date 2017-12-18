// 2017-1�б� ���α׷��ַ� 6��
// Lab6-ACM Candy War
#include <stdio.h>
#include <string.h>
int debug; // �߰� ������ ����ϴ� flag

// ��� ����� ������ ĵ�� ������ �ִ��� check
// ������ return 1
// �ٸ��� return 0
int check_candys(int *candys, int n)
{
	int count = candys[0];
	int i, check = 1;

	for (i = 0; i < n; i++) {
		if (count != candys[i])
			return check = 0;
	}

	return check;
}

// ��� ����� ¦���� ĵ�� ������ �����Ѵ�.
void make_even(int *candys, int n)
{
	int i;
	if (debug)
		printf("¦�� ");
	for (i = 0; i < n; i++)
		if (candys[i] % 2 == 1)
			candys[i]++;
}
// ����ִ� ĵ���� ���� �������� �����Ѵ�.
// Circular Queue ���·� ����
// 0->1, 1->2, .. (n-1)-->0
void turn_over(int *candys, int n)
{
	int i, tmp1, tmp2;
	if (debug)
		printf("���� ");
	for (i = 0; i < n; i++)
		candys[i] /= 2;

	for (i = 0; i < n; i++) {
		if (i == n - 1) {
			tmp2 = candys[0];
			candys[0] += tmp1;
			break;
		}
		if (i == 0) {
			tmp1 = candys[i + 1];
			candys[i + 1] += candys[i];
			continue;
		}
		tmp2 = candys[i + 1];
		candys[i + 1] += tmp1;
		tmp1 = tmp2;
	}
}

// ��� ����� ������ �ִ� ĵ�� ����Ѵ�.
void print_candys(int round, int *candys, int n)
{
	int i;
	printf(" %d:  ", round);
	for (i = 0; i < n; i++)
		printf("%d ", candys[i]);
	printf("\n");
}

void main()
{
	int ntest;
	int i, n, candys[10];
	int round;

	printf("�߰����� ���(1/0) : \n");
	scanf("%d", &debug);
	
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)// candy[]�� �Է��� �޴´�.
			scanf("%d ", &candys[i]);
		round = 0;
		if (debug)
			printf("���� ");
		print_candys(round, candys, n);
		if (n == 1)// n==1�̸� ��� ������.
			goto label;
		make_even(candys, n);// ��� ����� ¦������ �����
		print_candys(round, candys, n);
		while (check_candys(candys, n) != 1) { // check_candys ��� ������ ������.
			round++;
			turn_over(candys, n);// turn_over ��������� 1/2�� �ְ�
			print_candys(round, candys, n);
			if (check_candys(candys, n) == 1) // check_candys ��� ������ ������.
				break;
			make_even(candys, n);// make_even Ȥ�� Ȧ������ ������ ��� ¦������ �����
			print_candys(round, candys, n);
		}
	label:
		printf("���  %d\n", round);
	}
}