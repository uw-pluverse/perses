



extern void free (void *);

char *p, buf3[10], d;
struct S { char a; int b; } *r;

void foo (void)
{
  char buf[10], buf2[10], c;
  static char buf4[10], e;
  char *q = buf;
  free (p);
  free (q);
  free (buf2);
  free (&c);
  free (buf3);
  free (&d);
  free (buf4);
  free (&e);
  free (&r->a);
  free ("abcd");
  free (L"abcd");
}
