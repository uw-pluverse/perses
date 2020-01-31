


extern void g (void);
extern void bar (int);

int
foo (int a)
{
  int i;

  for (i = 1; i < 100; i++)
    {
      if (i)
 g ();
    }
}
