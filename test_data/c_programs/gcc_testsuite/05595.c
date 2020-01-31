


int a;

void f (void)
{
  char b;

  for (;; a++)
    {
      char *p = &b, *q;
      *q = b < 0 & !!*p;
    }
}
