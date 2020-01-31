



struct S { unsigned b : 1; } a;

void
foo ()
{
  if (a.b)
    ;
}
