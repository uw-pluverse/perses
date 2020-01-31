extern void abort (void);



int f(int n)
{
  if (-(1 << (sizeof(int) * 8 - 2)) <= n && n <= (1 << (sizeof(int) * 8 - 2))-1)
    return 1;
  return 0;
}

int main ()
{
  if (f ((1 << (sizeof(int) * 8 - 2))))
    abort ();
  return 0;
}
