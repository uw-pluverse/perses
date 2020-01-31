





extern void abort (void);

int main()
{
  double a = 20;
  int i;

  for (i = 0; i < 10; ++i)
    a -= 2;

  if (a)
    abort();
  return 0;
}
