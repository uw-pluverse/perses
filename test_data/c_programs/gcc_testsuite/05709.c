


foo (int *p)
{
  int x = baz ();

  if (p == 0)
    goto L78;
  else
    {
      x = *p;

      if (p)
 x = x + 1;
L78:

      if (p)
 {
   x = baz (*p);

   if (p)
     return x + 3;
 }

      return x - 3;
    }
}
