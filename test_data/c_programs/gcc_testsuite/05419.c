


void foo();
void bla();
void bar();




void dont_thread_4 (int a, int nfirst)
{
  int i = 0;
  int first;

  if (a)
    first = 0;
  else
    first = 1;

  do
    {
      if (first)
 foo ();
      else
 bar ();

      first = nfirst;
      bla ();
    } while (i++ < 100);
}
