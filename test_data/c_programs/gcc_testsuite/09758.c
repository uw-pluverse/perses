





static char a;
char *b;

void foo (void)
{
  register char *c;

  c = b;
  *c = a;
}
