#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <x86intrin.h>

#define TAILLE_1 5000
#define TAILLE_2  256

uint64_t debut, delta;

uint64_t getClock ()
{
  uint64_t a, d;

  asm ("rdtsc" : "=a" (a),"=d" (d));
  return  (d << 32) | a;
}

int main(int argc, char * argv[])
{
  int tab[TAILLE_1][TAILLE_2];
  /* float tab[TAILLE_1][TAILLE_2]; */
  int i, j;
  long int somme1 = 0, somme2 = 0, somme3 = 0;
  
  /* On initialise le tableau */
  for (i = 0; i < TAILLE_1; i++)
    for (j = 0; j < TAILLE_2; j++)
      tab[i][j] = (i + j) % 100;
  
  /* Boucle interne par ligne */
  debut = getClock ();
  for (j = 0; j < TAILLE_2; j++)
    for (i = 0; i < TAILLE_1; i++)
      somme1 = somme1 + tab[i][j];
  delta = getClock () - debut;
  printf("Duree / ligne   : %10" PRIu64 "\n", delta);

  /* Boucle interne par colonne */
  debut = getClock ();
  for (i = 0; i < TAILLE_1; i++)
    for (j = 0; j < TAILLE_2; j++)
      somme2 = somme2 + tab[i][j];
  delta = getClock () - debut;
  printf("Duree / colonne : %10" PRIu64 "\n", delta);
  
  /* Boucle interne par ligne */
  debut = getClock ();
  for (i = 0; i < TAILLE_1; i++)
    for (j = 0; j < TAILLE_2; j++)
      {
        _mm_clflush(&tab[i][j]);
        somme3 = somme3 + tab[i][j];
      }
  delta = getClock () - debut;
  printf("Duree / l +flush: %10" PRIu64 "\n", delta);
  

return 0;
}
