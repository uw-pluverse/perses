


void bark (void);
int flag, hoist, y, z;

void
foo (void)
{
  if (flag)
    y = hoist + 4;
  else
    flag = 888;
  z = hoist + 4;
  bark ();
}
