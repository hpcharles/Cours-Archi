#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef TYPEELT tMatrix[NLINE][NCOL];

struct timeval time;
struct timezone tz;

long long start()
{
  gettimeofday (&time, &tz);
  return time.tv_sec*1000000+time.tv_usec;
}

long long stop(long long timeusec)
{
  long long fin;
  gettimeofday (&time, &tz);
  fin = time.tv_sec*1000000+time.tv_usec;
  return fin-timeusec;
}

void printMatrix(tMatrix a)
{
  int line, col;
  for (line = 0; line < NLINE; line++)
    {
      for (col = 0; col < NCOL; col++)
          printf("%08d ", (TYPEELT) a[line][col]);
      printf("\n");
    }
  printf("\n");
}

void cleanMatrix(tMatrix a)
{
  int line, col;
  for (line = 0; line < NLINE; line++)
    for (col = 0; col < NCOL; col++)
      a[line][col] = 0;
}

void sumMatrix(tMatrix a, tMatrix b, tMatrix res)
{
  int line, col;
  for (line = 0; line < NLINE; line++)
    for (col = 0; col < NCOL; col++)
      res[line][col] = a[line][col] + b[line][col];
}

long long mulMatrix(tMatrix a, tMatrix b, tMatrix res)
{
  int line, col, k;
  long long timeusec = start();
  for (line = 0; line < NLINE; line++)
    for (col = 0; col < NCOL; col++)
      {
        res[line][col] = 0;
        for (k = 0; k < NCOL; k++)
          res[line][col] += a[line][k] * b[k][col];
      }
  return stop(timeusec);
}

void diagMatrix(tMatrix a, TYPEELT value)
{
  int indice, line;
  indice = (NLINE < NCOL)?NLINE:NCOL;
  for (line = 0; line < indice; line++)
      a[line][line] = value;
}

void firstLineMatrix(tMatrix a, TYPEELT value)
{
  int col;
  for (col = 0; col < NCOL; col++)
      a[0][col] = value;
}

void firstColMatrix(tMatrix a, TYPEELT value)
{
  int line;
  for (line = 0; line < NCOL; line++)
      a[line][0] = value;
}

void randMatrix(tMatrix a)
{
  int line, col;
  for (line = 0; line < NLINE; line++)
    for (col = 0; col < NCOL; col++)
      a[line][col] = (TYPEELT) (rand () % 1000);
}

int main(int argc, char * argv[])
{
  tMatrix a, b, c;
  long long time;
  int i;
  cleanMatrix(a);  cleanMatrix(b);   cleanMatrix(c);
  randMatrix(a);  randMatrix(b);
  time = 0;
  for (i = 0; i< 1000; i++)
    time += mulMatrix(a, b, c);
  printf ("usec time of 1000 iteration : %lld\n", time);
#if 0

  /* printMatrix (a); */
  printMatrix (c);
#endif
  return 0;
}
