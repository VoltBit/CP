#include <stdio.h>
typedef struct mat matrice;
struct mat
{
	int L,C;
	int N;
	int LIN[];
	int COL[];
	float X[];
};
typedef struct pol polinom;
struct pol
{
	int grad;
	int coef[];
};
void p1()
{
	matrice *m1;
	m1 = (matrice *)malloc(sizeof(matrice));
}
void citire_matrice(matrice *m)
{
	int i;
	scanf("%i",&L);
	scanf("%i",&C);
	scanf("%i",&N);

}
void afisare_matrice(matrice *m)
{
	int i,j;
	for(i=0;i<m->L:;i++)
		for(j=0;j<m->C;j++)
}
void adunare_matrice(*m)
{

}
void p2()
{
	matrice *m;
	citire_matrice(m);
	afisare_matrice(m);
	adunare_matrice(m);
}
void p3(){}
void p4_bonus(){}

int main()
{
	int nr;
	printf("problema: "); scanf("%i",&nr); printf("%i\n",nr);
	switch(nr)
	{
		case 1: p1(); break;
		case 2: p2(); break;
		case 3: p3(); break;
		case 4: p4_bonus(); break;
		case 0: return 0;
		default: return 0;
	}

	return 0;
}