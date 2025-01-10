void *calloc (__SIZE_TYPE__, __SIZE_TYPE__);

int
x7 (void)
{
  int **md = calloc (1, 1);

  return md[0][0];

}
