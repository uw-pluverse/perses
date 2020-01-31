





void bar (void);
void foo(void)
{
  if (1)
    {
      goto bla;
    }
  else
    {
xxx:
 {
bla:
   bar ();
   return;
 }
      goto xxx;
    }
}
