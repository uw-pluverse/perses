




int
main ()
{
  int i, chunk;
  float c[50];

  chunk = 5;
#pragma omp parallel for shared (c, chunk) schedule (dynamic, chunk)
 for (i = 0; i < 50; i++)
    c[i] = i;

  return 0;
}
