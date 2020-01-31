


const int* foo (void)
{
  int *i;
  const int** cpi = (const int**) &i;
  i = 0;
  return *cpi;
}
