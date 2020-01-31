



typedef unsigned __int128 NT;




extern void do_not_go_away ();

void f (NT x, NT y)
{
  NT n = 1;
  n <<= (8 * sizeof (NT) - 1);
  if (x > n) return;
  if (y > n) return;
  NT z = x + y;
  if (z == 42) do_not_go_away ();
}
