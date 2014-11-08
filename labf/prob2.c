#include <stdio.h>
#define MAX 100

void p1()
{

	int i,j,n,v[100],aux;
	scanf("%i",&n);
	for(i = 0; i < n; i++)scanf("%i",&v[i]);
	for(i = 0; i < n; i++)
		for(j = 0; j < n-1; j++)
		if(v[j]>v[j+1])
		{
			aux = v[j];
			v[j] = v[j+1];
			v[j+1] = aux;
		}
	for(i = 0; i < n; i++)printf("%i ",v[i]);

}

void p2()
{

	printf("Problema2");

}

void p3(){}

void p4()
{

	int i,j,n,v[100],s=0,nr=0;
        scanf("%i",&n);
        for(i = 0; i < n; i++)scanf("%i",&v[i]);
        for(i = 0; i < n; i++)
	{
		s = s + v[i];
		if(s > s + v[i])
		{
			if(nr<s)nr = s;
			s = 0;
		}else s+=v[i];
	}
	printf("raspuns: %i",nr);

}

void p5()
{
	int i=-1,j,n,v[100],x,y;
        for(i = 0; i < n; i++)scanf("%i",&v[i]);
	scanf("%i",x); scanf("%i",y);
       	do
	{
		i++;
		scanf("%i",v[i]);
	}while(v[i] > 0);
}
void p6(){}

int main()
{

	int i,t;
	printf("nr_problema = "); scanf("%i",&t);
	switch(t)
	{

		case 1: p1(); printf("\n\n"); break;
		case 2: p2(); printf("\n\n"); break;
		case 3: p3(); printf("\n\n"); break;
		case 4: p4(); printf("\n\n"); break;
		case 5: p5(); printf("\n\n"); break;
		case 6: p6(); printf("\n\n"); break;
		default: printf("Exit\n\n");

	}

}
