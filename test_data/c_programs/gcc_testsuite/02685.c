
int f (int a, int b, int c, _Bool d, _Bool e, _Bool f, char g)
{
  if (g != 1 || d != 1 || e != 1 || f != 1) abort ();
  return a + b + c;
}

int main (void)
{
  if (f (1, 2, -3, 1, 1, 1, '\001'))
    abort ();
  exit (0);
}
