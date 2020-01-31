


void do_something_big (void);

int test2(int a)
{
   if (a<100)
     return 1;
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   do_something_big ();
   return 0;
}

void
test()
{
  test2(10);
  test2(20);
}
