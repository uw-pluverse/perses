



void bar (void);

void
foo (void *b, int *c)
{
again:
  switch (*c)
    {
    case 1:
      if (!b)
 {
   bar ();
   return;
 }
      goto again;
    case 3:
      if (!b)
 goto again;
    }
}
