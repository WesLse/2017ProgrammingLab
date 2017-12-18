// 2017-1학기 프로그래밍랩 6주
// Lab6-ACM Candy War
#include <stdio.h>
#include <string.h>
int debug; // 중간 과정을 출력하는 flag

// 모든 사람이 동일한 캔디를 가지고 있는지 check
// 같으면 return 1
// 다르면 return 0
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

// 모든 사람이 짝수개 캔디를 갖도록 조정한다.
void make_even(int *candys, int n)
{
	int i;
	if (debug)
		printf("짝수 ");
	for (i = 0; i < n; i++)
		if (candys[i] % 2 == 1)
			candys[i]++;
}
// 들고있는 캔디의 반을 우측으로 전달한다.
// Circular Queue 형태로 전달
// 0->1, 1->2, .. (n-1)-->0
void turn_over(int *candys, int n)
{
	int i, tmp1, tmp2;
	if (debug)
		printf("전달 ");
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

// 모든 사람이 가지고 있는 캔디를 출력한다.
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

	printf("중간과정 출력(1/0) : \n");
	scanf("%d", &debug);
	
	scanf("%d", &ntest);
	while (ntest--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)// candy[]에 입력을 받는다.
			scanf("%d ", &candys[i]);
		round = 0;
		if (debug)
			printf("시작 ");
		print_candys(round, candys, n);
		if (n == 1)// n==1이면 즉시 끝난다.
			goto label;
		make_even(candys, n);// 모든 사람을 짝수개로 만들고
		print_candys(round, candys, n);
		while (check_candys(candys, n) != 1) { // check_candys 모두 같으면 끝난다.
			round++;
			turn_over(candys, n);// turn_over 옆사람에게 1/2를 주고
			print_candys(round, candys, n);
			if (check_candys(candys, n) == 1) // check_candys 모두 같으면 끝난다.
				break;
			make_even(candys, n);// make_even 혹시 홀수개가 있으면 모두 짝수개를 만들고
			print_candys(round, candys, n);
		}
	label:
		printf("결과  %d\n", round);
	}
}