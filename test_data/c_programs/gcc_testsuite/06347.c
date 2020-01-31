



int a, *c;

void
f (void)
{
  int b = 0;

  for (a = 0;; a++)
    if (--b)
      {
 if (a)
 lbl:
   a++;

 c = &b;
 goto lbl;
      }
}
