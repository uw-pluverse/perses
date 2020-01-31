


extern void other_caller (void);

void
callee (void)
{
  return;
}

void
caller(void (*func) (void))
{
  func ();
}
