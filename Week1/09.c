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
	//��� ������ ����Ѵ�.
	for (i = 0; i < N; i++)
		printf("p[%d]=(%d, %d)\n", i, p[i].x, p[i].y);

	//P1,P2�� ���Ѵ�. �־��� ������ ����� ��
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
	
	printf("P1="); print_point(&P1); // ȣ�� ������ �����ؼ� print_point()�Լ��� �ϼ��� ��
	printf(" P2="); print_point(&P2);
	//������ ����Ѵ�.
	area = (ABS(P2.x - P1.x)) * (ABS(P2.y - P1.y));
	printf("  ����=%d\n", area);
	return 0;
}