//Dobre Andrei Ciprian 316CB
#include "bmp_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define EXTRA 5

typedef struct{
	unsigned char fMark1;
	unsigned char fMark2;
	signed int width;
	signed int height;
	signed int color;
}PPM_header;

typedef struct{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}RGB; //folosita in citirea bmp

typedef struct{
	unsigned int blue;
	unsigned int green;
	unsigned int red;
}RGB2; //folosita in citirea ppm

int detectare_tip(char v[21])
{
	//verific extensia fisierelor
	char *p,aux[21];
	strcpy(aux,v);
	p = strtok(aux,".");
	p = strtok(NULL,".");
	if(strcmp(p,"bmp") == 0)return 1;
	else
		if(strcmp(p,"pgm") == 0)return 2;
		else
			if(strcmp(p,"ppm") == 0)return 3;
	return 0;
}

void bmp_to_ppm( RGB **bmp_content, INFOHEADER *bmp_infohead, char fname[21])
{
	printf("bmp_to_ppm\n");
	int i,j;
	FILE *ppm_write = fopen(fname,"w");
	fprintf(ppm_write,"%c%c\n",'P','3');
	fprintf(ppm_write,"%i %i\n",bmp_infohead->width,bmp_infohead->height);
	fprintf(ppm_write,"%i\n",255);
	printf("\n%i ",bmp_infohead->height);
	printf("%i ",bmp_infohead->width);
	i = bmp_infohead->height-1;
	for(i = bmp_infohead->height-1; i >= 0; i--)
		for(j = 0; j < bmp_infohead->width; j++)
		{
			fprintf(ppm_write,"%i ",bmp_content[i][j].blue);
			fprintf(ppm_write,"%i ",bmp_content[i][j].green);
			fprintf(ppm_write,"%i ",bmp_content[i][j].red);
		}
	for(i = 0; i < bmp_infohead->height; i++)
		free(bmp_content[i]);
	free(bmp_content);
}

void bmp_to_pgm( RGB **bmp_content, INFOHEADER *bmp_infohead, char fname[21])
{
	int i,j,med;
	printf("bmp_to_pgm\n");
	FILE *pgm_write = fopen(fname,"w");
	fprintf(pgm_write,"%c%c\n",'P','2');
	fprintf(pgm_write,"%i %i\n",bmp_infohead->width,bmp_infohead->height);
	fprintf(pgm_write,"%i\n",255);
	for(i = bmp_infohead->height-1; i >= 0; i--)
		for(j = 0; j < bmp_infohead->width; j++)
		{
			med = (bmp_content[i][j].blue + bmp_content[i][j].red + bmp_content[i][j].green)/3;
			fprintf(pgm_write, "%i ", med);
		}
	for(i = 0; i < bmp_infohead->height; i++)
		free(bmp_content[i]);
	free(bmp_content);
}

void ppm_to_pgm( RGB2 **ppm_content, PPM_header *ppm_header, char fname[21])
{
	printf("ppm_to_pgm\n");
	int i,j,med;
	FILE *pgm_write = fopen(fname,"w");
	fprintf(pgm_write,"%c%c\n",'P','2');
	fprintf(pgm_write,"%i %i\n",ppm_header->width,ppm_header->height);
	fprintf(pgm_write,"%i\n",255);
	for(i = 0; i <ppm_header->height; i++)
		for(j = 0; j < ppm_header->width; j++)
		{
			med = (ppm_content[i][j].red + ppm_content[i][j].green + ppm_content[i][j].blue)/3;
			fprintf(pgm_write,"%i ", med);
		}
	for(i = 0; i < ppm_header->height; i++)
		free(ppm_content[i]);
	free(ppm_content);
}

RGB **citire_bmp(char bmp_name[21], FILEHEADER *bmp_head, INFOHEADER *bmp_infohead)
{
	int i=0,j;
	RGB **bmp_content;
	//deschidere fisiere si citire headere
	FILE *bmp_img = fopen(bmp_name,"rb");

	if(!bmp_img)
	{
		printf("Eroare fisier\n"); exit(1);
	}
	fread(bmp_head,sizeof(FILEHEADER),1,bmp_img);
	fread(bmp_infohead,sizeof(INFOHEADER),1,bmp_img);
	bmp_content = (RGB **)malloc(sizeof(RGB*)*bmp_infohead->height+EXTRA);
	//citesc informatiile de dupa header(pixelii) intr-o matrice de tip RGB

	for(i = 0; i < bmp_infohead->height; i++)
	{
		bmp_content[i] = (RGB *)malloc(sizeof(RGB)*bmp_infohead->width);
		for(j = 0; j < bmp_infohead->width; j++)
		{
			fscanf(bmp_img,"%c",&bmp_content[i][j].red);
			fscanf(bmp_img,"%c",&bmp_content[i][j].green);
			fscanf(bmp_img,"%c",&bmp_content[i][j].blue);
		}
	} i--;
	printf("%i \n",i);
	fclose(bmp_img);
	return bmp_content;
}

RGB2 **citire_ppm(char ppm_name[21],PPM_header *f_head)
{
	RGB2 **ppm_content;
	int i=0,j=0;
	FILE *ppm_img = fopen(ppm_name,"r");
	if(!ppm_img)
	{
		printf("Eroare fisier\n"); exit(1);
	}
	//citire header
	fscanf(ppm_img,"%c",&f_head->fMark1);
	fscanf(ppm_img,"%c",&f_head->fMark2);
	fscanf(ppm_img,"%i",&f_head->width);
	fscanf(ppm_img,"%i",&f_head->height);
	fscanf(ppm_img,"%i",&f_head->color);
	//alocare si citire continut
	ppm_content = (RGB2 **)malloc(sizeof(RGB2*)*f_head->height+EXTRA);
	for(i=0; i < f_head->height; i++)
	{
		ppm_content[i] = (RGB2 *)malloc(sizeof(RGB2)*f_head->width);
		for(j = 0; j < f_head->width; j++)
		{
			fscanf(ppm_img,"%d",&ppm_content[i][j].red);
			fscanf(ppm_img,"%d",&ppm_content[i][j].green);
			fscanf(ppm_img,"%d",&ppm_content[i][j].blue);
		}
	}
	printf("%i ",i);
	printf("%i \n",j);
	fclose(ppm_img);
	return ppm_content;
}

int **citire_pgm(char fname[21], int *width, int *height)
{
	int **pgm_content;
	char mark1,mark2;
	int color,i,j;
	FILE *pgm_img = fopen(fname,"r");
	if(!pgm_img)
	{
		printf("Eroare fisier\n"); exit(1);
	}
	fscanf(pgm_img,"%c%c",&mark1,&mark2);
	fscanf(pgm_img,"%i%i%i",width,height,&color);
	pgm_content = (int **)malloc(sizeof(int *)*(*height));
	for(i=0;i<*height;i++)
	{
		pgm_content[i] = (int *)malloc(sizeof(int)*(*width));
		for(j=0;j<*width;j++)
			fscanf(pgm_img,"%i",&pgm_content[i][j]);
	}
	return pgm_content;
}

void blur_pgm(char fname[21], int **pgm_content, int width, int height,int nr)
{
	int i,j,med; 
	char *p;
	if(nr == 0)
	{
		//formarea numelui fisierului cu blur
		p = strtok(fname,".");
		strcat(p,"_blur");
		p[strlen(p)]='\0';
		strcat(p,".pgm");
		strcpy(fname,p);
	}
	printf("%s\n",fname);
	FILE *output = fopen(fname,"w");
	fprintf(output,"%c%c\n",'P','2');
	fprintf(output,"%i %i\n%i\n",width,height,255);

	//blur pentru primul rand de pixeli
	med = (pgm_content[0][1] + pgm_content[1][0])/2;
	fprintf(output,"%i ",med);
	for(i=1;i<width-1;i++)
	{
		med = (pgm_content[0][i-1] + pgm_content[0][i+1] + pgm_content[1][i])/3;
		fprintf(output,"%i ",med);
	}
	med = (pgm_content[0][width-2] + pgm_content[1][width-1])/2;
	fprintf(output,"%i ",med);
	for(i=1;i<height-1;i++)
	{
		//blur pentru pixelii din marginea stanga
		med = (pgm_content[i-1][0] + pgm_content[i+1][0] + pgm_content[i][1])/3;
 		fprintf(output,"%i ",med);
 		//blur pentru pixelii din centru
		for(j=1;j<width-1;j++)
		{
			med = (pgm_content[i][j-1] + pgm_content[i][j+1] + pgm_content[i-1][j] + pgm_content[i+1][j])/4;
			fprintf(output,"%i ",med);
		}
		//blur pentru pixelii din marginea dreapta
		med = (pgm_content[i-1][j] + pgm_content[i+1][j] + pgm_content[i][j-1])/3;
		fprintf(output,"%i ",med);
	}
	//blur pentru ultimul rand de pixeli
	med = (pgm_content[height-2][0] + pgm_content[height-1][1])/2;
	fprintf(output,"%i ",med);
	for(i=1;i<width-1;i++)
	{
		med = (pgm_content[height-1][i-1] + pgm_content[height-1][i+1] + pgm_content[height-2][i])/3;
		fprintf(output,"%i ",med);
	}
	med = (pgm_content[height-2][width-1] + pgm_content[height-1][width-2])/2;
	fprintf(output,"%i ",med);

	if(nr<10)
	{
		printf("%i ",nr);
		pgm_content = citire_pgm(fname,&width,&height);
		fclose(output);
		blur_pgm(fname,pgm_content,width,height,++nr);
	}
	else
	{
		for(i = 0; i < height; i++)
			free(pgm_content[i]);
		free(pgm_content);
	}
}

RGB2 medie_rgb(RGB2 a, ...)
{
	//obtine media pentru fiecare componenta a pixelilor vecini
	int check=0,i=0,s_red=0,s_green=0,s_blue=0;
	RGB2 med,p;
	va_list args;
	va_start(args,a);
	p.red = a.red; p.green = a.green; p.blue = a.blue;
	do
	{
		if(p.red == 999)check = 1;
		else
		{
			s_red += p.red;
			s_green += p.green;
			s_blue += p.blue;
			i++;
			p = va_arg(args, RGB2);
		}
	}while(check == 0);
	med.red = s_red/i;
	med.green = s_green/i;
	med.blue = s_blue/i;
	return (med);
}

void blur_ppm(char fname[21], RGB2 **ppm_content, PPM_header size, int nr)
{
	int i,j; 
	RGB2 end,med;
	end.red=999;
	char *p;
	if(nr == 0)
	{
		p = strtok(fname,".");
		strcat(p,"_blur");
		p[strlen(p)]='\0';
		strcat(p,".ppm");
		strcpy(fname,p);
	}

	printf("%s\n",fname);
	FILE *output = fopen(fname,"w");
	fprintf(output,"%c%c\n",'P','3');
	fprintf(output,"%i %i\n%i\n",size.width,size.height,255);
	med = medie_rgb(ppm_content[0][1],ppm_content[1][0],end);
	fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
	//blur pentru primul rand de pixeli
	for(i=1;i<size.width-1;i++)
	{
		med = medie_rgb(ppm_content[0][i-1],ppm_content[0][i+1],ppm_content[1][i],end);
		fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
	}
	med = medie_rgb(ppm_content[0][(size.width-2)],ppm_content[1][(size.width-1)],end);
	fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
	for(i=1;i<size.height-1;i++)
	{
		//blur pentru pixelii din marginea stanga
		med = medie_rgb(ppm_content[i-1][0],ppm_content[i+1][0],ppm_content[i][1],end);
 		fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
 		//blur pentru pixelii din centru
		for(j=1;j<size.width-1;j++)
		{
			med = medie_rgb(ppm_content[i][j-1],ppm_content[i][j+1],ppm_content[i-1][j],ppm_content[i+1][j],end);
			fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
		}
		//blur pentru pixelii din marginea dreapta
		med = medie_rgb(ppm_content[i-1][j],ppm_content[i+1][j],ppm_content[i][j-1],end);
		fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
	}
	//blur pentru ultimul rand de pixeli
	med = medie_rgb(ppm_content[(size.height-2)][0],ppm_content[(size.height-1)][1],end);
	fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
	for(i=1;i<size.width-1;i++)
	{
		med = medie_rgb(ppm_content[(size.height-1)][i-1],ppm_content[(size.height-1)][i+1],ppm_content[(size.height-2)][i],end);
		fprintf(output,"%i %i %i ",med.red,med.green,med.blue);
	}
	med = medie_rgb(ppm_content[(size.height-2)][(size.width-1)],ppm_content[(size.height-1)][(size.width-2)],end);
	fprintf(output,"%i %i %i ",med.red,med.green,med.blue);

	if(nr<10)
	{
		printf("%i ",nr);
		ppm_content = citire_ppm(fname,&size);
		fclose(output);
		blur_ppm(fname,ppm_content,size,++nr);
	}
	else
	{
	for(i = 0; i < size.height; i++)
		free(ppm_content[i]);
	free(ppm_content);
	}
}

void crop_ppm(char fname[21], RGB2 **ppm_content, int height, int SJx, int SJy, int DSx, int DSy)
{
	int i, j;
	char *p;
	p = strtok(fname,".");
	strcat(p,"_crop");
	p[strlen(p)]='\0';
	strcat(p,".ppm");
	strcpy(fname,p);
	printf("%s\n",fname);
	FILE *output = fopen(fname,"w");
	fprintf(output,"%c%c\n",'P','3');
	fprintf(output,"%i %i\n%i\n",(DSx-SJx+1),(DSy-SJy+1),255);

	for(i = height-DSy-1; i < height-SJy; i++)
	{
		for(j = SJx; j < DSx+1; j++)
		{
			fprintf(output,"%u ",ppm_content[i][j].red);
			fprintf(output,"%u ",ppm_content[i][j].green);
			fprintf(output,"%u ",ppm_content[i][j].blue);
		}
	}
}

void crop_pgm(char fname[21], int **pgm_content, int height, int SJx, int SJy, int DSx, int DSy)
{
	int i, j;
	char *p;
	p = strtok(fname,".");
	strcat(p,"_crop");
	p[strlen(p)]='\0';
	strcat(p,".pgm");
	strcpy(fname,p);
	printf("%s\n",fname);
	FILE *output = fopen(fname,"w");
	fprintf(output,"%c%c\n",'P','2');
	fprintf(output,"%i %i\n%i\n",(DSx-SJx+1),(DSy-SJy+1),255);
	for(i = height-DSy-1; i < height-SJy; i++)
	{
		for(j = SJx; j < DSx+1; j++)
			fprintf(output,"%u ",pgm_content[i][j]);
	}
}

int main()
{
	int x,y,pgm_height,pgm_width,**pgm_content,i=0,SJx,SJy,DSx,DSy;
	char input[61],mod[9],file_name1[21],file_name2[21],*p;
	FILEHEADER f_head;
	INFOHEADER f_infohead;
	PPM_header ppm_header;
	RGB **bmp_content;
	RGB2 **ppm_content;
	while(1)
	{	//prelucrare input
		fgets(input,60,stdin);
		p = strtok(input," \n");
		strcpy(mod,p);
		if(strcmp(mod,"exit") == 0)break;
		if(strcmp(mod,"convert") == 0)
		{
			p = strtok(NULL," \n");
			strcpy(file_name1,p);
			p = strtok(NULL," \n");
			strcpy(file_name2,p);
		} 
		else if(strcmp(mod,"blur") == 0)
		{
			p = strtok(NULL," \n");
			strcpy(file_name1,p);
		}
		else if(strcmp(mod,"crop") == 0)
		{
			p = strtok(NULL," \n");
			strcpy(file_name1,p);
			p = strtok(NULL," \n");
			SJx = atoi(p);
			p = strtok(NULL," \n");
			SJy = atoi(p);
			p = strtok(NULL," \n");
			DSx = atoi(p);
			p = strtok(NULL," \n");
			DSy = atoi(p);
		}
		//selectare a operatiilor
		if(strcmp(mod,"convert") == 0)
		{
			x = detectare_tip(file_name1);
			y = detectare_tip(file_name2);
			switch(x)
			{
				case 1:
					bmp_content = citire_bmp(file_name1,&f_head,&f_infohead);
					if(y == 2)bmp_to_pgm(bmp_content,&f_infohead,file_name2);
						else if(y == 3)bmp_to_ppm(bmp_content,&f_infohead,file_name2);
							else printf("Eroare fisier 2");
					break;
				case 3:
					ppm_content = citire_ppm(file_name1,&ppm_header);
					if(y == 2)ppm_to_pgm(ppm_content,&ppm_header,file_name2); 
						else printf("Eroare fisier 2");
					break;
				case 0:
					printf("eroare extensie");
			}
		}
		else
			if(strcmp(mod,"blur") == 0)
			{
				x = detectare_tip(file_name1);
				if(x == 2)
				{
					pgm_content = citire_pgm(file_name1,&pgm_width, &pgm_height);
					blur_pgm(file_name1,pgm_content,pgm_width,pgm_height,0);
				}
				else if(x == 3)
				{
					ppm_content = citire_ppm(file_name1,&ppm_header);
					blur_ppm(file_name1,ppm_content,ppm_header,0);
				}
			}
			else if(strcmp(mod,"crop") == 0)
			{
				x = detectare_tip(file_name1);
				if(x == 2)
				{
					pgm_content = citire_pgm(file_name1,&pgm_width, &pgm_height);
					crop_pgm(file_name1,pgm_content, pgm_height, SJx, SJy, DSx, DSy);
					for(i = 0; i < pgm_height; i++)
						free(pgm_content[i]);
					free(pgm_content);
				}
				else if(x == 3)
				{
					ppm_content = citire_ppm(file_name1,&ppm_header);
					crop_ppm(file_name1,ppm_content, ppm_header.height, SJx, SJy, DSx, DSy);
					for(i = 0; i < ppm_header.height; i++)
						free(ppm_content[i]);
					free(ppm_content);
				}
			}
			else return 0;
	}
			
	return 0;
}