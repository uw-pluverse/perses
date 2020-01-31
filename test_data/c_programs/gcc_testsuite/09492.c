



void g ();

void
f (int b)
{
  for (int i = 0; i < b; i + b)
    g ();

  for (int i = 0; i < b; b)
    g ();
  for (int i = 0; i < b; !i)
    g ();
  for (!b;;)
    g ();
  for (;; b * 2)
    g ();
  ({
     b / 5;
     b ^ 5;
   });
}
