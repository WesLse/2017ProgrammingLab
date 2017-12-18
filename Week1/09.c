#include <stdio.h>

#define N 4
#define ABS(x) (x >= 0) ? x : -x

struct Point {
	int x;
	int y;
};

void print_point(struct Point *p)
{
	printf("(%d, %d)", p->x, p->y);
}

int main()
{
	struct Point p[N] = { {1,2},{6,1},{3,4},{4,5} };
	struct Point P1, P2;
	int area;
	int i;
	//모든 점들을 출력한다.
	for (i = 0; i < N; i++)
		printf("p[%d]=(%d, %d)\n", i, p[i].x, p[i].y);

	//P1,P2를 구한다. 주어진 변수만 사용할 것
	P1 = p[0];
	for (i = 0; i < N; i++)
	{
		if (p[i].x < P1.x)
			P1.x = p[i].x;
		if (p[i].y < P1.y)
			P1.y = p[i].y;
	}
	P2 = p[0];
	for (i = 0; i < N; i++)
	{
		if (p[i].x > P2.x)
			P2.x = p[i].x;
		if (p[i].y > P2.y)
			P2.y = p[i].y;
	}
	
	printf("P1="); print_point(&P1); // 호출 형식을 참조해서 print_point()함수를 완성할 것
	printf(" P2="); print_point(&P2);
	//면적을 계산한다.
	area = (ABS(P2.x - P1.x)) * (ABS(P2.y - P1.y));
	printf("  면적=%d\n", area);
	return 0;
}