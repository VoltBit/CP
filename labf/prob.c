#include <stdio.h>
#define MAX 100
void problema1(int v[100],int n)
{
	int i,max = -100, m, min=1000,nr=0,poz; float s=0;
	for(i=0;i<n;i++)
	{
		if(min>v[i])min = v[i];
		if(max<v[i]){max = v[i]; poz = i;}
		s = s + v[i];
	} m = n;
	for(i=0;i<n;i++)if(s/m < v[i])nr++;
	printf("min = %i\npoz_max = %i\nmedie = %.2f\nnumar = %i\n",min,poz,s/n,nr);
}

void sort_selectie(int v[MAX], int n)
{

	int i,j,aux;
	for(i = 0; i < n; i++)
		for(j = i; j < n-1; j++)
		if(v[j]>v[j+1])
		{
			aux = v[j];
			v[j] = v[j+1];
			v[j+1] = aux;
		}

	for(i=0;i<n;i++)printf("%i",v[i]);

}

int main()
{
	int n,v[100],i,t;
	scanf("%i",&n);
	for(i=0;i<n;i++)scanf("%i",&v[i]);
	printf("t = "); scanf("%i",&t);
	switch(t)
	{
		case 1: problema1(v,n); break;
		case 2: sort_selectie(v,n); break;
	}

}

