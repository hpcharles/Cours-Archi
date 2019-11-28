#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>


uint64_t debut, delta, a, d;


int main()
{
	
/* 
La fonction __rdfscp() n'est pas toujours autorisée par Linux
 
uint32_t x;
debut = __rdtscp(&x);
 
delta = __rdtscp(&x) - debut;
 
On utilisera donc la version en assembleur x86
asm volatile("rdtsc" : "=a" (a),"=d" (d));
debut = (d << 32) | a;
 
*/
   
    

       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       debut = (d << 32) | a;
    
    
       /* Insérer votre programme ici */


       asm volatile("rdtsc" : "=a" (a),"=d" (d));
       delta = ((d << 32) | a) - debut;

       printf("Duree : %lld\n", delta);


return 0;
}
