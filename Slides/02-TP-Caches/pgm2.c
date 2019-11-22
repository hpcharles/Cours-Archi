#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>

#define TAILLE_1 5000
#define TAILLE_2 256


uint64_t debut, delta, a, d;
uint32_t x;

int main()
{
int tab[TAILLE_1][TAILLE_2];
int i, j;


/* On initialise le tableau */
for (i = 0; i < TAILLE_1; i++)
    for (j = 0; j < TAILLE_2; j++)
	    tab[i][j] = (i + j) % 100;



       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       debut = (d << 32) | a;

    
       /* Programme à insérer ici */
    

       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       delta = ((d << 32) | a) - debut;

	   printf(  "Duree : %lld\n", delta);



return 0;
}
