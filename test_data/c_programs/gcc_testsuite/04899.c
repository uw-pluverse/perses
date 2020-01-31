






_Bool *baz ();

int *bar ();

int
foo (void)
{
 (*bar ())++;
 ++(*bar ());
 (*bar ())--;
 --(*bar ());
 (*baz ())++;
 ++(*baz ());

 (*baz ())--;
 --(*baz ());

 return 0;
}
