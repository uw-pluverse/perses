






void abort (void);
void exit (int);

void foo (void)
{
  int i;
  char *p;

  p = (char *) &i;
  *p = -10;
  if (* (unsigned char *) p != 0x100 - 10)
    abort ();
}

int main (void)
{
  if ((127*2 +1) == 255)
    foo ();
  exit (0);
}
