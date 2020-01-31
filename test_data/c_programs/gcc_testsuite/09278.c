




extern int g;
extern void bar (void);

int
foo (int x)
{
  int a, b, *c = (int *) 0;
  for (a = 0; a < 10; ++a)
    {
      bar ();
      for (b = 0; b < 5; ++b)
 {
   x = 0;
   c = &x;
   g = 1;
 }
    }
  *c = x;
  for (x = 0; x != 10; x++)
    ;
  return g;
}
