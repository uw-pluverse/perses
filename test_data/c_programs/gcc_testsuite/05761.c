


void dont_remove (void);

void foo(int k)
{
  int i = 1;
  void *label;

  label = k ? &&x : &&y;

  if (k == 1)
    goto *label;

  i = 0;
  goto z;
z:
x:
  if (i)
    dont_remove ();
y: ;
}
