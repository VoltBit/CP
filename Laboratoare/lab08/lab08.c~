#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void p1()
{
	int var,n,aux,max,gasit,i,*v;
	//char *v; ???
	scanf("%i",&n);
	scanf("%i",&max);
	v=malloc(n*sizeof(int));
	srand(time(NULL)); //???
	for(i=0;i<n;i++)
	{
		*(v+i)=rand()%(max+1);
	}
	do
	{
		gasit=0;
		for(i=0;i<n-1;i++)
			if(*(v+i)>*(v+i+1))
			{
				aux = *(v+i);
				*(v+i) = *(v+i+1);
				*(v+i+1) = aux;
				gasit=1;
			}
	}while(gasit==1);
	for(i=0;i<n;i++)printf("%i ",*(v+i));
	printf("\n");
	free(v);
}
void p2()
{
	int **mat1,**mat2,l1,l2,c1,c2,i,j,k,s;
	scanf("%i",&l1);
	scanf("%i",&c1);
	scanf("%i",&l2);
	scanf("%i",&c2);
	mat1 = malloc(l1*sizeof(int *));
	mat2 = malloc(l2*sizeof(int *));
	for(i=0;i<c1;i++)
		{
			mat1[i]=malloc((i+1)*sizeof(int));
			for(j=0;j<i+1;j++)scanf("%i",&*( *(mat1 + j) + i));
		}
	for(i=0;i<c2;i++)
		{
			mat2[i]=malloc((c2-i)*sizeof(int));
			//for(j=0;j<c2-i;j++)scanf("%i",&*( *(mat2 + j) + i));
		}

	for(i=0;i<l1;i++)
		{
			printf("\n");
			for(j=0;j<c1;j++)
					printf("%i",mat1[i][j]);
		}
		printf("\n");
	/*for(i=0;i<l2;i++)
		{
			printf("\n");
			for(j=0;j<c2;j++)
					printf("%i",mat2[i][j]);
		}*/

	for(i=0;i<l1;i++)
	{
		printf("\n");
		for(j=0;j<c2;j++)
		{
			s=0;
			for(k=0;k<c1;k++)
				s+=mat1[i][k]*mat2[k][j];
			printf("%i",s);
		}
	}
	free(mat1);
	//free(mat2);
}

char *build_number(int x)
{
	int nr=0,aux,i;
	char *v;
	aux = x;
	while(aux)
	{
		nr++;
		aux/=10;
	}
	v = malloc((nr+2)*sizeof(char));
	*v = nr;
	for(i=1;i<=*v;i++)
	{
		v[i] = x%10;
		x/=10;
		//printf("%i ",v[i]);
	}
	//printf("\n");
	return v;
}

char *add_numbers(char *a, char *b)
{
	int i,n,t=0,m;
	char *c;
	if(a[0]>b[0]){n = b[0]; m = a[0];}
	else
		{n = a[0]; m = b[0];}
	c = calloc(m+1,sizeof(char));
	c[0]=m;
	for(i=1;i<=n;i++)
	{
		c[i] = a[i] + b[i] + t;
		t = c[i]/10;
		c[i]%=10;
	}
	if(t)
	{
		if(n==m)c[0]++;
		c[n+1]=t;
	}
	t=0;
	if(a[0]>b[0])
		for(i=n+1;i<=c[0];i++)
		{
			c[i] = a[i] + c[i] + t;
			t = c[i]/10;
			c[i]%=10;
		}
		else
			for(i=n+1;i<=c[0];i++)
			{
				c[i] = b[i] + c[i] + t;
				t = c[i]/10;
				c[i]%=10;
			}
	if(t)
	{
		c[0]++;
		c[c[0]]=t;
	}
	/* afisare reversed
	for(i=0;i<=c[0];i++)printf("%i ",c[i]);
	printf("\n");*/
	/*afisare normala*/
	for(i=c[0];i>0;i--)printf("%i",c[i]);
	printf("\n");
	return c;
}

char *multiply_numbers(char *a, char *b)
{

	char *c;
	int i,j,t=0;
	c = calloc((a[0] + b[0] + 1),sizeof(char));
	c[0] = a[0] + b[0] - 1;
	for(i=1; i<=a[0]; i++)
	{
		for(j=1; j<=b[0]; j++)
			c[i+j-1]+=a[i]*b[j];
	}
	for(i=1; i<=c[0]; i++)
	{
		c[i]+=t;
		t = c[i]/10;
		c[i]%=10;
	}
	if(t)c[++c[0]]=t;
	for(i=c[0];i>0;i--)printf("%i",c[i]);
	printf("\n");
	return c;
}

void p3()
{
	char *x,*y,*aux;
	int i;
	//printf("a) "); build_number(12345);
	//printf("b) "); add_numbers(build_number(9999),build_number(9999));
	printf("c) \n");
	//____________fibonacci:______________
	printf("%i: ",1); x = build_number(1);
	printf("%i: ",2); y = build_number(1);
	for(i=2;i<100;i++) //270 free(x) ?????
	{
		printf("%i: ",i+1);
		aux = y;
		y = add_numbers(x,y);
		free(x);
		x = aux;
	}
}
void p4_bonus()
{
	char *x,*y,*z;
	int i;
	printf("a) \n");
	x = build_number(98999);
	y = build_number(6375);
	printf("x = "); x = add_numbers(x,y);
	printf("y = "); y = add_numbers(x,y);
	printf("x * y = "); z = multiply_numbers(x,y);
	free(x); free(y); free(z);
	printf("b) \n");
	y = build_number(1);
	for(i=1;i<=50;i++)
	{
		printf("%i! = ",i);
		x = build_number(i);
		z = y;
		y = multiply_numbers(x,y);
		free(x); free(z);
	}
}
void p5_bonus(){}
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
		case 5: p5_bonus(); break;
		case 0: return 0;
		default: return 0;
	}
	return 0;
}
