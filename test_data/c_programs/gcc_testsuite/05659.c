





extern void abort (void);
extern void exit (int);

main ()
{
  int table, c, elt;
  int tem = Faref (table, elt);
  Faset (table, elt, c);
  Faset (table, c, tem);
  exit (0);
}

int j = 0;

int __attribute__ ((noinline)) Faref (table, elt)
{
  j = 1;
  return 0;
}

int __attribute__ ((noinline)) Faset (table, elt, c)
{
  if (j != 1)
    abort ();
  return 0;
}
