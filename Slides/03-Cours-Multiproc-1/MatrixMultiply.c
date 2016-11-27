#include <stdio.h>
#include <stdlib.h>

typedef TYPEELT tMatrix[NLINE][NCOL];

void printMatrix(tMatrix a)
{
  int line, col;
  for (line = 0; line < NLINE; line++)
    {
      for (col = 0; col < NCOL; col++)
          printf("%08f ", a[line][col]);
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

void mulMatrix(tMatrix a, tMatrix b, tMatrix res)
{
  int line, col, k;
  for (line = 0; line < NLINE; line++)
    for (col = 0; col < NCOL; col++)
      {
        res[line][col] = 0;
        for (k = 0; k < NCOL; k++)
          res[line][col] += a[line][k] * b[k][col];
      }
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
  int i;
  cleanMatrix(a);  cleanMatrix(b);   cleanMatrix(c);
  randMatrix(a);  randMatrix(b);
  for (i = 0; i< 1000; i++)
    mulMatrix(a, b, c);
  /* printMatrix (a); */
  printMatrix (c);
  return 0;
}
