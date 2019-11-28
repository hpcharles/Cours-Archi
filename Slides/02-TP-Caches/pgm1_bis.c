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
long int somme1 = 0, somme2 = 0;

_mm_clflush(&x);

for (i = 0; i < TAILLE; i++)
	tab[i] = i;

	
/* debut = __rdtscp(&x);
delta = __rdtscp(&x) - debut;
*/

       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       debut = (d << 32) | a;

       for (i = 0; i < TAILLE; i++)
	   somme1 = somme1 + tab[i];

       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       delta = ((d << 32) | a) - debut;

       printf("Duree : %lld\n", delta);



       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       debut = (d << 32) | a;

       for (i = 0; i < TAILLE; i++)
	   {
       _mm_clflush(&tab[i]);
	   somme2 = somme2 + tab[i];
	   }

       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       delta = ((d << 32) | a) - debut;

	printf(  "Duree : %lld\n", delta);

return 0;
}
