


extern void abort (void);
extern void oof (int);

int
com(int *blah)
{
  int z = *blah;
  if (z == 256)
    {
      oof (z);
      abort ();
    }
  return *blah;
}
