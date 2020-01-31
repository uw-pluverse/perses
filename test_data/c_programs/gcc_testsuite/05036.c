




extern void bar(void);

void foo (int x, int a)
{

  if (x < a)
    return;
  if (x != a)
    return;


  bar ();
}
