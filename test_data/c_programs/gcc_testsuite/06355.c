




extern void abort (void);

unsigned short s;
unsigned int i;
unsigned long l;
unsigned char v = -1;

void __attribute__((noinline,noclone))
bar (int t)
{
  if (t == 2 && s != 0xff)
    abort ();
  if (t == 1 && i != 0xff)
    abort ();
  if (t == 0 && l != 0xff)
    abort ();
}

void __attribute__((noinline,noclone))
foo (unsigned char *a, int t)
{
  unsigned char r = v;

  if (t == 2)
    s = (unsigned short) r;
  else if (t == 1)
    i = (unsigned int) r;
  else if (t == 0)
    l = (unsigned long) r;
  bar (t);
}

int main(void)
{
  foo (&v, 0);
  foo (&v, 1);
  foo (&v, 2);
  return 0;
}
