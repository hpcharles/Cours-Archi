#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>


uint64_t debut, delta, a, d;
uint32_t tab[256 * 16];
uint32_t x;
uint8_t u;

int main()
{
    int i;

    /* Initialisation du tableau */
    for (i = 0; i < 256 ; i++)
        tab [i * 16] = 1 ;
    
#if INVALIDATE == 1
    
    for (i = 0; i < 256 ; i++)
        _mm_clflush(&tab [i * 16]);
    
#endif
    
    

    asm volatile("rdtsc" : "=a" (a),"=d" (d));
    debut = (d << 32) | a;
    
    for (i = 0; i < 256 ; i++)
        u = tab [i * 16] ;

    asm volatile("rdtsc" : "=a" (a),"=d" (d));
    delta = ((d << 32) | a) - debut;

    printf("Duree (%s) : %lld\n", INVALIDATE ? "inv" : "cached", delta);

    /* Pour que le compilo n'efface pas tout en optimisant ! */
    return (char)tab[random() % (256 * 16)];;
}
