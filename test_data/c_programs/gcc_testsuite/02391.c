extern void abort (void);

struct s { int a:12, b:20; };

struct s x = { -123, -456 };

int
main (void)
{
  if (x.a != -123U || x.b != -456U)
    abort ();
  return 0;
}
