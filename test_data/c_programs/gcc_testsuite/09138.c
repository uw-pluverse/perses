


void bar (int);

void
foo ()
{
 int index = 0;

 for (index; index <= 10; index--)


   bar ((0xcafe + index) * 0xdead);
}
