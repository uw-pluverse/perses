





void bar (int *);

void
foo ()
{
  int i,j;
 for (i=0; i < 100; ++i)
    {
 bar(&i);
 }
}
