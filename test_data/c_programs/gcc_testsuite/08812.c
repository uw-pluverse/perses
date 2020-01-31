



int g;
void bar();
void blah(int);

int foo (int n, int l, int m, int r)
{
  int v;

  if (n || m || r || l)
    v = r;

  if (m) g++;
  else bar();

  if ( n || m || r || l)
      blah(v);

  if ( n )
      blah(v);

  if ( l )
      blah(v);

  return 0;
}

int foo_2 (int n, int l, int m, int r)
{
  int v;

  if (n || m || r )
    v = r;

  if (m) g++;
  else bar();

  if ( n || m || r || l)
      blah(v);

  return 0;
}
