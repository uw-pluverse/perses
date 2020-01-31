





extern void abort (void);

int
foo (int parm)
{
  int varj, varm;

  for (varj = 0; varj < 10; varj++)
    {
      if (varj == 5)
 continue;
      if (varj == 7 && !parm)
 goto exitlab;
      if (varj == 9)
 break;
      varm = varj;
    }

exitlab:
  return varm;
}

int
main (void)
{
  if (foo (0) != 6)
    abort ();
  if (foo (1) != 8)
    abort ();
  return 0;
}
