





void *jmpbuf[6];

void
foo (void)
{
  __builtin_setjmp (jmpbuf);
}

int
main (void)
{
  return 0;
}
