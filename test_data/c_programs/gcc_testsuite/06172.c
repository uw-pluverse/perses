



extern char v[];

int
foo ()
{
  int k = 0;
  typedef char T[64];
  for (int i = 0; i < 64; i++)
    k += (*(T *) &v[0])[i];
  return k;
}
