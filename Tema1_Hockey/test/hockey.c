//Dobre Andrei Ciprian 316CB
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
typedef struct punct punct;
struct punct
{
	double x;
	double y;
};

void data_reader(punct teren[4], punct poarta[4], double *x, double *y, double *alfa)
{
	int i; double a,b,al;
	for(i=0;i<4;i++)
	{
		scanf("%lg",&teren[i].x);
		scanf("%lg",&teren[i].y);
	}
	for(i=0;i<4;i++)
	{
		scanf("%lg",&poarta[i].x);
		scanf("%lg",&poarta[i].y);
	}
	scanf("%lg",&a); *x = a;
	scanf("%lg",&b); *y = b;
	scanf("%lg",&al); *alfa = al;
}
void intersectie(punct M, double alfa, punct teren[4], int c, double *x, double *y)
{
	//double PI = 3.14159265;
	/*
	+ functia realizeaza intersectia dreaptei determinata de punctul M si
	  unghiul alfa, cu laturile terenului folosindu-se de ecuatia dreptei in plan:
	  y - y0 = tan(alfa)(x - x0)
	+ parametrul c al functiei contine un cod pentru laturile terenului
	*/
	switch(c)
	{
		case 12:
		*x = teren[1].x;
		*y = M.y + tan(alfa * PI / 180)*(*x - M.x); 
		break;
		case 23:
		*y = teren[3].y;
		*x = (*y - M.y)/tan(alfa * PI / 180) + M.x;
		break;
		case 30:
		*x = teren[3].x; 
		*y = M.y + tan(alfa * PI / 180)*(teren[3].x - M.x);
		break;
		case 10:
		*y = teren[1].y;
		*x = (*y - M.y)/tan(alfa * PI / 180) + M.x;
		break;
	}
}
void goal_check(punct poarta[4],int id1, int id2, double x, double y)
{
	if(y > poarta[id1].y && y < poarta[id2].y) 
		if(id1 == 0 && id2 == 1)
        {
        	printf("%3.3f %3.3f\r",x,y);
            printf("%i\r\n",-1);
        }
        else 
        	{
        		printf("%3.3f %3.3f\r",x,y);
        		printf("%i\r\n",1);
			}
	else
	{
		printf("%3.3f %3.3f\r",x,y);
		printf("%i\r\n",0);
	}
}
int main()
{
	punct teren[4]; punct poarta[4]; punct M;
	double alfa,x,y;
	data_reader(teren,poarta,&x,&y,&alfa);
	M.x = x; M.y = y; 
	/*
	+ in functie de unghiul cu care pucul se deplaseaza, exista sansa ca el sa loveasca
	  doua ziduri, algoritmul determina care dintre cele doua ziduri este lovit
	+ colturile terenului sunt numerotate de la 0 la 3 iar zidurile sunt identificate
	  in functie de colturi: 30 10 12 23
	  (3)----------------------------(2)
	  |                90              |
	  |                                |
	  |      180                0      |
	  |                                |
	  |               270              |
	  (0)----------------------------(1)
	*/
while(1)//programul ruleaza pana cand energia cinetica devine 0
{
	if(alfa == 0 || alfa == 90 || alfa == 180 || alfa == 270)
	{
		if(alfa == 180 && poarta[0].y <= M.y && poarta[1].y >= M.y)
		{
			printf("%3.3f %3.3f\r",x,y);
			printf("%3.3f %3.3f\r",poarta[0].x,M.y);
			printf("%i\r\n",-1);
			return 0;
		}else if(alfa == 0 && poarta[2].y <= M.y && poarta[3].y >= M.y)
		{
			printf("%3.3f %3.3f\r",x,y);
			printf("%3.3f %3.3f\r",poarta[2].x,M.y);
			printf("%i\r",1);
			return 0;
		}
		printf("%i\r",0);
		return 0;
	}
	printf("%3.3f %3.3f\r",M.x,M.y);
	if(alfa > 0 && alfa < 90) //poate lovi zidul 12 sau zidul 23
	{
		/*se intersecteaza traiectoria pucului cu zidul 12,
		  apoi verifica daca aceasta se afla intradevar in interiorul terenului
		  conditia implica si egalitate pentru cazul in care pucul loveste chiar 
		  coltul terenului, in aceasta situatie mantinela se considera ca fiind atinsa
		  si este verificata si conditia pentru gol*/
		intersectie(M,alfa,teren,12,&x,&y);
		if(y <= teren[2].y) 
		{
			printf("%3.3f %3.3f\r",x,y);
			goal_check(poarta,2,3,x,y);
			return 0;
		}
		/*in cazul in care pucul nu a lovit mantinela
		  se intersecteaza traiectoria cu al doilea zid posibil
		  si se retine locul de unde ricoseaza si se modifica unghiul alfa
		 */
		intersectie(M,alfa,teren,23,&x,&y);
		if(x < teren[2].x)//pucul loveste zidul 23
		{
			M.x = x; 
			M.y = y; 
			alfa = 360 - alfa;
		}
	}
	else if(alfa > 90 && alfa < 180)
	{
		intersectie(M,alfa,teren,30,&x,&y);
		if(y <= teren[3].y)
		{
			printf("%3.3f %3.3f\r",x,y);
			goal_check(poarta,0,1,x,y);
			return 0;
		}
		intersectie(M,alfa,teren,23,&x,&y);
		if(x > teren[3].x)
		{
			M.x = x; 
			M.y = y; 
			alfa = 180 + (180 - alfa);
		}
	}
	else if(alfa > 180 && alfa < 270)
	{
		intersectie(M,alfa,teren,30,&x,&y);
		if(y >= teren[0].y)
		{
			printf("%3.3f %3.3f\r",x,y);
			goal_check(poarta,0,1,x,y);
			return 0;
		}
		intersectie(M,alfa,teren,10,&x,&y);
		if(x > teren[0].x)
		{
			M.x = x; 
			M.y = y; 
			alfa = 180 + (180 - alfa);
		}
	}
	else if(alfa > 270 && alfa < 360)
	{
		intersectie(M,alfa,teren,12,&x,&y);
		if(y >= teren[1].y)
		{
			printf("%3.3f %3.3f\r",x,y);
			goal_check(poarta,2,3,x,y);
			return 0;
		}
		intersectie(M,alfa,teren,10,&x,&y);
		if(x < teren[1].x)
		{
			M.x = x; 
			M.y = y; 
			alfa = 360 - alfa;
		}
	}
}
	return 0;
}