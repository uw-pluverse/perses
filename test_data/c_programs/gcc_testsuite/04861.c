



struct J { long buf[8]; };
extern int setjmp (struct J[1]);
void foo (int);

void
bar (void)
{
  int k;
  foo (-1);
 for (k = 0; k < 10; ++k)
    {
      struct J j[1];
      if (setjmp (j) == 0)
 foo (k);
    }
  foo (-2);
}
