

void blah();
void bar (int);
int gflag;

void foo()
{
   int v;
   if (gflag)
     v = 10;

   blah();

   if (gflag)
    bar(v);
}
