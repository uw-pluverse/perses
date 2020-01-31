




int foo (int v1[], int v2[])
{
  int r, i, j;

  for (j = 0; j < 64; j++)
    for (i = 0; i < 64; i++)
      r = v1[j] + v2[i];

  return r;
}
