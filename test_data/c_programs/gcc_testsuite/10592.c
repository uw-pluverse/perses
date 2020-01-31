

extern void foo (void);
extern int i;
void
bar (void)
{
  switch (i)
    {
    case 0:
      foo ();
      break;
    case 1:
      break;
    }


  switch (i)
    {
    case 0:
      foo ();
      break;
    case 1:
      break;
    }
}
