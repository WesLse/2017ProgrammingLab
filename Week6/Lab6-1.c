// 2017-1학기 프로그래밍랩 6주
// Lab6-1 행렬 배열 사용 연산
#include <stdio.h>
#define ROWS	3
#define COLS	3
void print_matrix(int m[ROWS][COLS])
{
	int i, j;

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			printf("%2d ", m[i][j]);
		}
		printf("\n");
	}
}
void add_matrix(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS])
{
	int i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			c[i][j] = a[i][j] + b[i][j];
}
void sub_matrix(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS])
{
	int i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			c[i][j] = a[i][j] - b[i][j];
}
void main()
{
	int A[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int B[ROWS][COLS] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};
	int C[ROWS][COLS] = {0};

	printf("Matrix 배열 사용\n");
	printf("A = \n"); 	print_matrix(A);
	printf("B = \n"); 	print_matrix(B);
	add_matrix(A, B, C); 
	printf("A + B = \n"); print_matrix(C);
	sub_matrix(B, A, C);
	printf("B - A = \n"); print_matrix(C);
}