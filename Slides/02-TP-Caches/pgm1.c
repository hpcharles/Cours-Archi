#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>

#define TAILLE 10000


uint64_t debut, delta, a, d;
uint32_t x;

int main()
{
int tab[TAILLE];
int i;
long int somme = 0;

/* initialisation du tableau */
for (i = 0; i < TAILLE; i++)
	tab[i] = i;



       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       debut = (d << 32) | a;

       for (i = 0; i < TAILLE; i++)
            somme1 = somme1 + tab[i];

       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       delta = ((d << 32) | a) - debut;

       printf("Duree : %lld\n", delta);


return 0;
}
