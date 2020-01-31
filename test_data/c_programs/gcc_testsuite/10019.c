




__inline int f ()
{
  static int i;
  int i2 = i;
  i = i2 + 1;
  return i;
}

int g () { return f (); }

int main ()
{
  if (f() != 1
      || g() != 2
      || f() != 3)
    return 1;
  return 0;
}
