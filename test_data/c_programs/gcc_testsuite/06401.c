




extern void abort (void);
int a, b, d[10];
long long c;

int
main ()
{
  int e;
  for (e = 0; e < 10; e++)
    d[e] = 1;
  if (d[0])
    c = a = (b == 0 || 1 % b);
  if (a != 1)
    abort ();
  return 0;
}
