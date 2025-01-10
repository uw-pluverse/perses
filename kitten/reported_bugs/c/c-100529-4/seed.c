



void bar ();

void
foo (char a)
{
  union C { int d[100.0]; char *e; };
  bar ((union C) &a);
}
