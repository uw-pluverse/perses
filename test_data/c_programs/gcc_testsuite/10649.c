


extern void fn2 (void);
extern int a;

void
fn1 ()
{
  a = -1;
  fn2 ();
  a &= 1;
}
