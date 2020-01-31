






void foo (void);
void bar (int a)
{
  if (a == 16 || a == 23) foo ();
  if (a == -110 || a == -128) foo ();
}
