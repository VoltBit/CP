/*-- utils.c --*/

#include "database.h"

/* - functia de alocare a spatiului necesar initial pentru un grup de
     maxim MP persoane care fac NA analize. 
     Functia intoarce NULL sau adresa spatiului alocat */
ADB aloca(int MP, int NA)
{      
       ADB ag;
       int i, *p; /* indice, adresa vector vect_analize */
       
       ag = (DB*)malloc(sizeof(DB));
       if(!ag) 
        return NULL;
       ag->nr_pers_max = MP;

       ag->vect_pers = (Pers*)calloc(MP, sizeof(Pers));
       if(!ag->vect_pers) 
       {
        free(ag); 
        return NULL;
       }

       ag->vect_analize = (int*)calloc(MP * NA, sizeof(int));
       if (!ag->vect_analize)
       { 
         free(ag->vect_pers); free(ag);
         return NULL;
       }
       
       ag->nr_analize = NA;
       ag->nr_pers_curent = 0;

/* au reusit toate alocarile; pentru fiecare persoana [i] 
   memoreaza in campul vect_analize adresa zonei destinate a3lor sale
*/
       for(i = 0; i < MP; i++)
         ag->vect_pers[i].analize = ag->vect_analize + i * NA;
       return ag;
}


/* afiseaza, pentru fiecare nume, cod_identif, ocupatie si analize */
void afiseaza(DB *ag)
{ Pers *as = ag->vect_pers, *xs = as + ag->nr_pers_curent; 
  int *p, *s;     /* adresa analiza, limita sup.p */

  printf("\n%i persoane\n", ag->nr_pers_curent);

  /* se parcurge vectorul de persoane */
  for (; as < xs; as++)
  { 
    printf("%2li. %-30s %s %-11s|%i| ", as - ag->vect_pers + 1, 
                as->nume, as->cod_identif, as->ocupatie, as->grupa_sanguina);
    
    /* parcurg vectorul de analize */
    for (p = as->analize, s = p + ag->nr_analize; p < s; p++)
      printf("%3i ", *p);
    printf("\n");
  }
}

/* elibereaza o DB alocata*/
void elibereaza(ADB* aag)
{ int i;

  free((*aag)->vect_analize);
  free((*aag)->vect_pers);
  free(*aag);
  *aag = NULL;
}