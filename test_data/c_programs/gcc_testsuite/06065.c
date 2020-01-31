


extern int printf (const char *, ...);

int
main ()
{
  int variable = 0;
  int p = 1;
  while (1)
    {
      if (p)
        break;
      variable = variable + 1;
      if (variable == 10)
        break;
    }
  printf("%d\n", variable);
}
