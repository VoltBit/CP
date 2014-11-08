#include <stdio.h>

typedef struct reg reg;
struct reg
{
	int sum;
	int pas;
	int directie;
}reg_A[100],reg_B[100];

void citire(int A[10]][10], int *n, int *m)
{
	int i,j,a,b;
	scanf("%i",&a); scanf("%i",&b); *n = a; *m = b;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)scanf("%i",&A[i][j]);
}

void inmultire_matrice(int A[10][10], int B[10][10])
{
	int i,j;
}
void suma(int A[10][10],int pas, int directie, char check)
{
	int i,j,s=0;
	if(directie == 0)
	{	
		for(i=0;i<=pas;i++)
			for(j=0;j<=pas;j++)s+=A[i][j];
		if(check == 'A'){reg_A[contor].pas = pas; reg_A.sum = s; reg_A.directie = directie;}
		else {reg_B[contor].pas = pas; reg_B.sum = s; reg_B.directie = directie;}
	}
	else if(directie == 1)
	{	
		for(i=0;i<=pas;i++)
			for(j=0;j<=pas+1;j++)s+=A[i][j];
		if(check == 'A'){reg_A[contor].pas = pas; reg_A.sum = s; reg_A.directie = directie;}
		else {reg_B[contor].pas = pas; reg_B.sum = s; reg_B.directie = directie;}
	}
	else
	{	
		for(i=0;i<=pas+1;i++)
			for(j=0;j<=pas;j++)s+=A[i][j];
		if(check == 'A'){reg_A[contor].pas = pas; reg_A.sum = s; reg_A.directie = directie;}
		else {reg_B[contor].pas = pas; reg_B.sum = s; reg_B.directie = directie;}
	}
}

int main()
{
	int A[10][10],B[10][10],n,m,p,j,i;
	citire(A,n,m);
	citire(B,m,p);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)


}