#include <stdio.h>
#include <stdlib.h>

int f (int a, int b){  return a+b;}
int g (int a, int b){  return a*b;}

int main(int argc, char * argv[])
{
  int nf, ng;
  int result, i;
  
  result = 0;
  nf = atoi (argv[1]);
  ng = atoi (argv[2]);
  
  for (i = 0; i < nf; i++)
    result += f(result, i);
  for (i = 0; i < ng; i++)
    result += g(result, i);
  printf ("%d %d %d\n", nf, ng, result);

  return 0;
}
