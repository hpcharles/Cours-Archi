typedef TYPEELT tMatrix[NLINE][NCOL];

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
