




extern void abort();



void func(int i)
{




  if ((i < 0) && (i >= 0))
    abort();
  if ((i > 0) && (i <= 0))
    abort();
  if ((i >= 0) && (i < 0))
    abort();
  if ((i <= 0) && (i > 0))
    abort();

  if ((i < 77) && (i >= 77))
    abort();
  if ((i > 77) && (i <= 77))
    abort();
  if ((i >= 77) && (i < 77))
    abort();
  if ((i <= 77) && (i > 77))
    abort();


  if (! ((i < 0) || (i >= 0)))
    abort();
  if (! ((i > 0) || (i <= 0)))
    abort();
  if (! ((i >= 0) || (i < 0)))
    abort();
  if (! ((i <= 0) || (i > 0)))
    abort();

  if (! ((i < 77) || (i >= 77)))
    abort();
  if (! ((i > 77) || (i <= 77)))
    abort();
  if (! ((i >= 77) || (i < 77)))
    abort();
  if (! ((i <= 77) || (i > 77)))
    abort();

  return;
}

int main()
{
  func(0);
  func(1);
  return 0;
}
