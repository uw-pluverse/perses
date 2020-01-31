


extern void foo2 (short*);

void
tr4 (short array[], int n)
{
  int x;
  if (n > 0)
    for (x = 0; x < n; x++)
      foo2 (&array[x]);
}
