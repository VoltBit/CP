//Dobre Andrei Ciprian 316CB
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int verificare_cuvant(char *v)
{/*functia verifica daca exista mai mult de 2 caractere alaturate*/
	if(strlen(v)==1)
	{
		if(isalnum(v[0]))return 0;
		else return 1;
	}
	else return 0;
}
int numar_spatii(char *v)
{
	unsigned int i,nr=0;
	for(i=0;i<strlen(v);i++)
		if(v[i]==' ')nr++;
	return nr;
}
int analiza_cuvant(char *str, int *config)
{
	/*-realizeaza vectorul de configuratie
	  -returneaza lungimea fiecarui cuvant
	*/
	int s,i,j;
	if(verificare_cuvant(str) == 1)
	{
		if(strchr("'-_",str[0]))config[62]++;
		else if('"'==str[0])config[62]++;
		return 1;
	}
	s = strlen(str);
	for(i='a';i<='z';i++)
		for(j=0;j<s;j++)
		{
			if( str[j] == i)
				config[i - 'a']++; 
			else
			if( str[j] == i - 'a' + 'A')
				config[i - 'a' + 26]++;
		}
	for(i=0;i<s;i++)
	{
		if(isdigit(str[i]))config[52 + str[i]-'0']++;
		else
			if(strchr("'-_",str[i]))config[62]++;
			else if('"'==str[i])config[62]++;
	}
	return s;
}
int analiza_linie(char *v, int *config, int *numar_litere, int *non_cuvinte)
{
	/*-returneaza numarul de cuvinte de pe linie
	  -returneaza prin parametru numarul de litere din linie*/
	int nr=0,nr2=0;
	char *aux,*str;
	aux = malloc(200 * sizeof(char));
	strcpy(aux,v);
	str = strtok(aux," \n");
	while(str!=NULL)
	{
		*numar_litere += analiza_cuvant(str,config);
		if(verificare_cuvant(str) == 0)nr++;
		else nr2++;
		str = strtok(NULL," \n");
	}
	*non_cuvinte+=nr2;
	return nr;
}
void interpretare_rezultate(int nr_cuv, int nr_lit, int nr_lin, int nr_sp, int non_cuv, int *config)
{
	int i,nr_char_freq=0;
	float med1,med2,m=0;
	char ch;
	printf("Rezultat:\n");
	med1 = (float)nr_cuv / (float)nr_lin;
	printf("%.2f nr mediu cuvinte pe linie\n",med1);
	med2 = (float)(nr_lit-non_cuv) / (float)nr_cuv;
	printf("%.2f lungime medie cuvant\n",med2);
	printf("%i numar total caractere cu spatii\n",nr_lit+nr_sp);
	printf("%i numar total caractere fara spatii\n",nr_lit);
	for(i=0;i<=62;i++)nr_char_freq+=config[i];
	for(i=0;i<=61;i++)
	{
		if(i<=25) ch = 'a' + i;
		else 
			if(i<=51)ch = 'A' + i - 26;
		else ch= '0' + i - 52;
		if(nr_char_freq>0)
		m = (float)config[i]*100 / (float)nr_char_freq;
		printf("Frecventa lui \"%c\" este %.2f\n",ch,m);
	}
}
int main()
{
	/*algoritmul se bazeaza pe un vector config care retine numarul
	  de aparitii ale caracterelor*/
	int n,aux,numar_cuvinte=0,numar_sp=0,numar_litere=0,non_cuvinte=0,*config;
	char *v;
	v = malloc(201 * sizeof(char));
	config = calloc(63, sizeof(int));
	scanf("%i",&n);
	fgets(v, 200, stdin);
	aux=n;
	while(aux>0)
	{
		fgets(v, 200, stdin);
		numar_sp += numar_spatii(v);
		numar_cuvinte += analiza_linie(v,config,&numar_litere,&non_cuvinte);
		aux--;
	}
	if(n>0)
		interpretare_rezultate(numar_cuvinte,numar_litere,n,numar_sp,non_cuvinte,config);
	free(v);
	return 0;
}