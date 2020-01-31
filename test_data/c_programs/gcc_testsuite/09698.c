




extern int puts (const char *);

int
main (void)
{
  int i, j = 8;
#pragma omp parallel
 {
    puts ("foo");
    for (i = 1; i < j - 1; i++)
      ;
  }
  return 0;
}
