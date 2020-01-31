void bar (void);

void
foo (int x, unsigned long long y)
{
 bar ();
 for (int i = 0; i < 10; i++)
      bar ();
 bar ();
 for (unsigned long long int i = 0; i < y; i++)
      bar ();
 bar ();
 for (int i = 0; i < 10; i++)
      bar ();
 bar ();
 for (unsigned long long int i = 0; i < y; i++)
      bar ();
}
