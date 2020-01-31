


extern void abort (void);



float a[1024], b[1024], c[1024];
int k[1024];

__attribute__((noinline, noclone)) void
f (void)
{
  int i;
  for (i = 0; i < 1024; i++)
    {
      a[i] = b[k[i]];
      b[i] = c[i];
    }
}

int main ()
{
  int i;

  for (i = 0; i < 1024; i++)
  {
    k[i] = i%2;
    b[i] = i;
    c[i] = 179;
  }

  f ();

  if (a[2] != 179 || a[3] != 179)
    abort ();

  return 0;
}
