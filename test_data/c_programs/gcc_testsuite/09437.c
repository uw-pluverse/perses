extern void abort (void);

int main ()
{
  int w = ~(int) 0;

  if (w != 2147483647)
    abort ();

  return 0;
}
