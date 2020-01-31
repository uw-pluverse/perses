


extern unsigned int foo (int*) __attribute__((pure));

unsigned int
tr1 (int array[], unsigned int n)
{
  int sum = 0;
  unsigned int x;
  for (x = 0; x < n; ++x)
    sum += foo (&array[x]);
  return sum;
}
