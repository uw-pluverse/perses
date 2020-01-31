




struct foo
{
  _Bool a : 1;
} sf;

extern void abort (void);
extern void exit (int);

int
main (void)
{
  int i;
  for (i = 0; i < sizeof (struct foo); i++)
    *((unsigned char *)&sf + i) = (unsigned char) -1;
  sf.a = 2;
  if (sf.a != 1)
    abort ();
  sf.a = 0;
  if (sf.a != 0)
    abort ();
  sf.a = 0.2;
  if (sf.a != 1)
    abort ();
  sf.a = &sf;
  if (sf.a != 1)
    abort ();
  exit (0);
}
