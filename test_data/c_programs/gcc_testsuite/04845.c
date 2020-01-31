



void
foo (int x)
{
  int i = 0;
 for (i = (i & x); i < 10; i = i + 2)
    ;
  i = 0;
 for (i = 0; i < (i & x) + 10; i = i + 2)
    ;
  i = 0;
 for (i = 0; i < 10; i = i + ((i & x) + 2))
    ;
}
