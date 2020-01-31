


int
f (void)
{
  int r = 0;

  r |= acc_on_device ();
  r |= acc_on_device (1, 2);
  r |= acc_on_device (3.14);
  r |= acc_on_device ("hello");

  return r;
}
