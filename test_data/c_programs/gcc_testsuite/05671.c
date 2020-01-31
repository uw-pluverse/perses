


void foo();
void bla();
void bar();




void dont_thread_1 (void)
{
  int i = 0;
  int first = 1;

  do
    {
      bla ();
      bla ();
      bla ();
      if (first)
 foo ();
      else
 bar ();

      first = 0;
      bla ();
    } while (i++ < 100);
}
