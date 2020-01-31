


void foo();
void bla();
void bar();

void dont_thread_3 (int nfirst)
{
  int i = 0;
  int first = 0;

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
