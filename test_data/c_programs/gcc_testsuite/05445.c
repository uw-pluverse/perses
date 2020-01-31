


void foo();
void bla();




void thread_latch_through_header (void)
{
  int i = 0;
  int first = 1;

  do
    {
      if (first)
 foo ();

      first = 0;
      bla ();
    } while (i++ < 100);
}
