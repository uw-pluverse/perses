


void
fn1 (int a)
{
  const int x = a;
  if (x && x) {}
  if (x && (int) x) {}
  if ((int) x && x) {}
  if ((int) x && (int) x) {}
}

void
fn2 (int a)
{
  const int x = a;
  if (x || x) {}
  if (x || (int) x) {}
  if ((int) x || x) {}
  if ((int) x || (int) x) {}
}
