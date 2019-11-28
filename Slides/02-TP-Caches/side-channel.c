/*****************************************/
/* Programme écrit par                   */
/* Arthur VIANES - KALRAY                */
/* Nov. 2019                             */
/*****************************************/

#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>

#define SIZE 17

/* Écrire dans cette variable force le compilo et le CPU
 * à ne pas optimiser l'exécution de l'instruction load */
volatile uint8_t u;


/* Mesure du temps */
static inline uint64_t rdtsc() {
  uint64_t a, d;
  asm volatile("rdtsc" : "=a" (a),"=d" (d));
  return (d << 32) | a;
}

/* Retourne l'index du maximum dans le tableau */
int max_index(int *array, int start, int end) {
  int value = 0, index = 0, i;
  for (i = start; i <= end; i++) {
    if (array[i] > value) {
      value = array[i];
      index = i;
    }
  }
  return index;
}

/* Fonction pour envoyer 4bit d'information par cache side channel */
void side_channel_write(uint32_t tab[SIZE][256 * 16], int n) {
  int i;

  /* On Flush la case n du tableau. Les lignes de cache de
   * cette cellule seront plus longue à accéder.
   * Note: la valeur de n n'est jamais écrite dans tab. */
  for (i = 0; i < 256 ; i++)
    _mm_clflush(&tab [n][i * 16]);
}


/* Fonction pour lire 4bit d'information par cache side channel */
int side_channel_read(uint32_t tab[SIZE][256 * 16]) {
  int time[SIZE];
  int i, j, debut, fin;

  /* On mesure le temps d'accès de chaque case du tableau */
  for (j = 0; j < SIZE ; j++) {

    debut = rdtsc();

    for (i = 0; i < 256 ; i++)
      u = tab [j][i * 16] ;

    fin = rdtsc();

    time[j] = fin - debut;
  }

  printf("mesures:\n");
  printf("idx   ticks\n");
  for (j = 0; j < SIZE ; j++)
    printf("%3d %6lld\n", j, time[j]);

  /* On cherche la case la plus longue à accéder.
   * Son indexe correspond à notre information.
   *
   * On ignore la premiere case car le cache
   * d'instruction etait froid. */
  return max_index(time, 1, SIZE-1);
}


int main (int argc, char **argv) {
  int i=0, j;
  int data_write = atoi(argv[1]);
  int data_read;

  uint32_t tab[SIZE][256 * 16]  __attribute__((aligned(4096)));

  /* Initialisation du tableau pour que
   * l'OS assigne des pages à notre tableau */
  for (j = 0; j < SIZE ; j++) {
    for (i = 0; i < 256 ; i++) {
      tab [j][i * 16] = 1;
    }
  }

  /* Écriture d'information par cache side channel */
  printf("Information transmise: %d\n\n", data_write);

  side_channel_write(tab, data_write);

  /* Lecture d'information par cache side channel */
  data_read = side_channel_read(tab);

  printf("\nInformation mesurée: %d\n", data_read);

  return 0;
}
