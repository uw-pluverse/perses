
int a;
int b[100];
void abort (void);

inline void
cold_function ()
{
  int i;
  for (i = 0; i < 99; i++)
    if (b[i] / (b[i+1] + 1))
      abort ();
}

inline void
hot_function ()
{
  int i;
  for (i = 0; i < 99; i++)
    if (b[i] / (b[i+1] + 1))
      abort ();
}

int
main ()
{
  int i;
  for (i = 0; i < 100; i++)
    {
      if (a)
        cold_function ();
      else
        hot_function ();
    }
  return 0;
}
