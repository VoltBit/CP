#include <stdio.h>
 
#define MAX	100
 
void read_matrix(int a[MAX][MAX], int *n)
{
	int i, j;
 
	scanf("%d", &(*n));
	for (i = 0; i < *n; i++)
		for (j = 0; j < *n; j++)
			scanf("%d", &a[i][j]);
}
 
int main(void)
{
	int a[MAX][MAX], n = 1, i, j;
 
	read_matrix(a, &n);
 	printf("%i %i\n",n,a[0][0]);
	for(i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
 
	return 0;
}
