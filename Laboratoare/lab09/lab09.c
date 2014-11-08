#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ordCresc(char **c, int n)
{
	char *aux,*aux2,**a;
	int i,g,j,*v,e;
	aux = malloc(101*sizeof(char));
	aux2 = malloc(101*sizeof(char));
	v = malloc(101*sizeof(int));
	a = malloc(11 * sizeof(char *));
	for(i=0;i<10;i++)
	{
		a[i] = malloc(100*sizeof(char));
		strcpy(a[i],c[i]);
	}
	for(i=0;i<n;i++)v[i] = strlen(c[i]);
	printf("\n1) Afisare ordine lungimi: ");
	do
	{
		g=0;
		for(i=0;i<n-1;i++)
			if(v[i]>v[i+1])
			{
				e = v[i];
				v[i] = v[i+1];
				v[i+1] = e;
				strcpy(aux,a[i]);
				strcpy(a[i],a[i+1]);
				strcpy(a[i+1],aux);
				g=1;
			}
	}while(g==1);
	for(i=0;i<n;i++)
		printf("%s ",a[i]);
	printf("\n1) Afisare ordine alfabetica: ");
	do
	{
		g = 0;
		for(i=0;i<n-1;i++)
		{
			aux = strdup(c[i]);
			aux2 = strdup(c[i+1]);
			for(j=0;j<(int)strlen(aux);j++)
				if(aux[j]>='A' && aux[j]<='Z')aux[j] = 'a'+aux[j]-'A';
			for(j=0;j<(int)strlen(aux2);j++)
				if(aux2[j]>='A' && aux2[j]<='Z')aux2[j] = 'a'+aux2[j]-'A';
			if(strcmp(aux,aux2)>0)
			{
				strcpy(aux,c[i]);
				strcpy(c[i],c[i+1]);
				strcpy(c[i+1],aux);
				g=1;
			}
		}
	}while(g==1);
	for(i=0;i<n;i++)
		printf("%s ",c[i]);
}
void p1()
{
	char **c;
	int i=0;
	c = malloc(11 * sizeof(char *));
	for(i=0;i<10;i++)
	{
		c[i] = malloc(101*sizeof(char));
		fgets(c[i],100,stdin);
		//puts(c[i]);
	}
	ordCresc(c,i);
}
int p2()
{
	char *v;
	int n,i;
	v = malloc(201*sizeof(char));
	fgets(v,200,stdin);
	fgets(v,200,stdin);
	n = strlen(v);
	for(i=0;i<n;i++)
		if(v[i]==' '){strcpy(v+i,v+i+1); n--;}
	n--;
	for(i=0;i<n/2;i++)
	{
		
		if(v[i] != v[n-i-1])
		{
			printf("Nu este palindroma!\n");
			return 0;
		}
	}
	printf("Este palindroma!\n");
	return 0;
}
void p3()
{
	char *p,*v;
	v = malloc(200*sizeof(char));
	fgets(v,200,stdin); fgets(v,200,stdin);
	p = strtok(v," ,.-\n");
	while(p!='\0')
	{
		printf("%s\n",p);
		p = strtok(NULL," ,.-\n");
	}
}
void p4()
{
	char *p,*v,*s;
	int nr=0,g,i;
	v = malloc(201*sizeof(char));
	s = malloc(201*sizeof(char));
	fgets(s,200,stdin);
	fgets(s,200,stdin); 
	fgets(v,200,stdin);
	s[strlen(s)-1]='\0'; puts(s);
	p = strtok(v," ,.-\n");
	while(p!='\0')
	{
		if(strcmp(p,s)==0)nr++;
		p = strtok(NULL," ,.-\n");
	}
	printf("numar de aparitii: %i\n",nr);
}
void p5()
{
	char *v,*st1,*st2,*p,*aux;
	v = malloc(501*sizeof(char));
	aux = malloc(501*sizeof(char));
	st1 = malloc(101*sizeof(char));
	st2 = malloc(101*sizeof(char));
	fgets(st1,100,stdin); 
	fgets(st1,100,stdin); puts(st1);
	fgets(st2,100,stdin); puts(st2);
	fgets(v,500,stdin);
	st2[strlen(st2)-1]='\0';
	puts(v);
	p = strstr(v,st1);
	puts(p);
	while(p != '\0')
	{
		strcpy(aux,p+strlen(st1)); puts(aux);
		memmove(p,st2,strlen(st2));
		strcat(p,aux);
		p = strstr(p+1,st1);
		printf("!!!");
	}
	puts(v);
}
void p6(){}
int main()
{
	int nr;
	printf("problema: "); scanf("%i",&nr); printf("%i\n",nr);
	switch(nr)
	{
		case 1: p1(); break;
		case 2: p2(); break;
		case 3: p3(); break;
		case 4: p4(); break;
		case 5: p5(); break;
		case 6: p6(); break;
		case 0: return 0;
		default: return 0;
	}

	return 0;
}
