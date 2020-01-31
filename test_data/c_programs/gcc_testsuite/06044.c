


void foo();
void bla();
void bar();



void dont_thread_2 (int first)
{
  int i = 0;

  do
    {
      if (first)
 foo ();
      else
 bar ();

      first = 0;
      bla ();
    } while (i++ < 100);
}
