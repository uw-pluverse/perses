


extern void abort (void);
extern void exit (int);

int
main (void)
{
  struct { int count: 2; } s = { -2 };
  while (s.count-- != -2)
    abort ();
  exit (0);
}
