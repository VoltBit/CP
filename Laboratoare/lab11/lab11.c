#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int file_size(FILE *f)
{
	int size;
	fseek(f,0,2);
	size = ftell(f);
	fseek(f,0,0);
	return size;
}

void stergere_cuvant()
{
	//am rezolvat problema citind din fisier cuvant cu cuvant
	//si scriindu-le (folosind un filtru pentru cuvantul cautat) 
	//intr-un alt fisier apoi am redenumit noul fisier si 
	//l-am sters pe cel vechi
	int size,x;
	char v[81],file_name[31],cuvant[21];
	printf("Fisier: "); fgets(file_name,30,stdin);
	file_name[strlen(file_name)-1]='\0'; //sterge endline
	printf("Cuvant: "); fgets(cuvant,20,stdin);
	cuvant[strlen(cuvant)-1]='\0'; //sterge endline
	FILE *f1 = fopen(file_name,"r");
	FILE *f2 = fopen("txt.out","w");
	size = file_size(f1);
	printf("dimensiunea initiala: %i\n",size);
	while( fscanf(f1,"%s",v) != EOF )
		if(strcmp(v,cuvant) != 0)fprintf(f2,"%s ",v);
	remove(file_name);
	rename("txt.out",file_name);
	fclose(f1);
	fclose(f2);
	f1 = fopen(file_name,"r");
	size = file_size(f1);
	printf("dimensiunea finala: %i\n",size);
	fclose(f1);
}

typedef struct{
	int zi,luna,an;
}data;

typedef struct{
	char nume[31],prenume[31],data_raw[13];
	data data_depundere;
	float suma_depusa;
}articol;

void prelucrare_date(char data_r[13],articol *art)
{
	//functia nu este neaparat necesara, converteste data
	//dintr-un string intr-un format (int,int,int)
	char *p;
	int n[4],i=0;
	p = strtok(data_r,".");
	while(p!=NULL)
	{
		if(p[0]=='0')
			{ p[0]=p[1]; p[1]='\0';}
		n[i] = atoi(p); i++;
		p = strtok(NULL,".");
	}
	art->data_depundere.zi = n[0];
	art->data_depundere.luna = n[1];
	art->data_depundere.an = n[2];
}

void scriere_articol(articol *art)
{
	FILE *bfile = fopen("fisier_date","wb");
	fwrite(art->nume,sizeof(char), sizeof(art->nume), bfile);
	fwrite(art->prenume,sizeof(char), sizeof(art->prenume), bfile);
	fwrite(art->data_raw,sizeof(char), sizeof(art->data_raw), bfile);
	fwrite(&art->suma_depusa,sizeof(float),sizeof(art->suma_depusa),bfile);
}

void articole_binar()
{
	//rezolvarea problemei 2
	articol art1,art2;
	char data_r[13];
	printf("Nume: "); fgets(art1.nume,30,stdin);
	printf("Prenume: "); fgets(art1.prenume,30,stdin);
	printf("Data (zz.ll.aaaa): "); fgets(art1.data_raw,12,stdin);
	printf("Suma depusa: "); scanf("%f",&(art1.suma_depusa));
	strcpy(data_r,art1.data_raw);
	prelucrare_date(data_r,&art1);
	scriere_articol(&art1);
}

void citire_bin1()
{
	//citirea fisierului lab11p2.bin
	int size,i;
	FILE *fbinar = fopen("lab11p2.bin","rb");
	char *v;
	v = (char *)malloc(sizeof(char)*(file_size(fbinar)+1));
	fread(v,file_size(fbinar),1,fbinar);
	//afisarea caracterelor omise de fread
	for(i=0;i<file_size(fbinar);i++)
    	printf("%c", ((char *)v)[i]);
}
void scriere_nr_random()
{
	int n,*x,i,y; char v[31];
	srand(time(NULL));
	printf("nume fisier: "); fgets(v,30,stdin);
	v[strlen(v)-1]='\0';
	printf("n: "); scanf("%i",&n);
	FILE *fisier = fopen(v,"wb");
	x = &y;
	for(i=0;i<n;i++)
	{
		y = rand()%1000;
		printf("%i ",y);
		fwrite(x,sizeof(int),1,fisier);
	}
}
int prim(int x)
{
	int i;
	for(i=2;i<=x/2;i++)
		if(x%i == 0) return 0;
	return 1;
}
void citire_bin2()
{
	int size,i,x,s=0,s_impar=0,s_prim=0,*p;
	char c;
	FILE *fbinar = fopen("lab11p4.bin","rb");
	size = file_size(fbinar); size/=4;
	printf("Numar de intregi: %i\n",size);
	fseek(fbinar,0,0);
	p=&x;
	while(!feof(fbinar))
	{
		fread(p,sizeof(int),1,fbinar);
		printf("%i ",x);
		if(x>0)
		{
			printf("%i ",x);
			s+=x;
			if(x%2)s_impar+=x;
			if(prim(x))s_prim+=x;
		}
	}
	printf("\nSuma: %i\n",s);
	printf("Suma impare: %i\n",s_impar);
	printf("Suma prime: %i\n",s_prim);
}
int main()
{
	stergere_cuvant();
	//articole_binar();
	//citire_bin1(); //lab11p2.bin
	//scriere_nr_random();
	//citire_bin2(); //lab11p4.bin
	return 0;
}
