



static int e;

int
foo ()
{
  return "foo1" != (void *) 0
  && "foo2" != (const char *) ((void *) 0)
  && "foo3" != (const char *) ((void *) (10 - 10))
  && "foo4" != (const char *) ((void *) (&e - &e))
  && "foo5" != "foo6";
}
