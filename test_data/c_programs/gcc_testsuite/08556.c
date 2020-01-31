






static __attribute__ ((always_inline)) void
baz ()
{
}

static __attribute__ ((always_inline)) int
bar ()
{
 out:
  baz ();
  goto out;
}

int
foo ()
{
  long res;

  res = bar ();
}
