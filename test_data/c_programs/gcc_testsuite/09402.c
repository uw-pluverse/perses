




void abort (void);

int main (void)
{
  int i;
  int x[100000];

  for (i = 0; i < 10000; i++)
    x[i] = x[i+10000];

  for (i = 0; i < 10000; i++)
    {
      if (x[i] != x[i+10000])
       abort ();
    }

  return 0;
}
