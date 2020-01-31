



int g;
void bar();
void blah(int);

int foo (int n, int l, int m, int r)
{
  int v;

  if (n > 10)
    v = r;

  if (m) g++;
  else bar();

  if ( (n > 10) && (l < 100))
      blah(v);

  if ( n > 100 )
      blah(v);

  return 0;
}

int foo_2 (int n, int l, int m, int r)
{
  int v;

  if (n > 10)
    v = r;

  if (m) g++;
  else bar();

  if ( n < 10)
      blah (v);


  return 0;
}
