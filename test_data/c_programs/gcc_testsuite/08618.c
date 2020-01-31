



int func (int x);
void recv (int (* funcptr) (double x));
void call (void)
{
  recv (func);
}
