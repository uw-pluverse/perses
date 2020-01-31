extern void impossible (void);

void f(__int128 x)
{
  unsigned __int128 y;
  unsigned __int128 z;
  if (x < -7)
    return;
  if (x > 2)
    return;
  y = x;
  z = y * y;
  if (z == 666)
    impossible ();
}

void g(unsigned __int128 x)
{
  unsigned __int128 y;
  unsigned __int128 z;
  unsigned __int128 m = -1;
  m = m / 2;
  if (x < m-2)
    return;
  if (x > m-1)
    return;
  y = x;
  z = y * y;




  if (z == 7)
    impossible ();
}
