


int x = 6;

int
main ()
{
  int v;
 x = x * 7 + 6;
 x = x * 7 ^ 6;
 x = x - 8 + 6;
 x = x ^ 7 | 2;
 x = x / 7 * 2;
 x = x / 7 / 2;
 { v = x; x = x * 7 + 6; }
 { v = x; x = x * 7 ^ 6; }
 { v = x; x = x - 8 + 6; }
 { v = x; x = x ^ 7 | 2; }
 { v = x; x = x / 7 * 2; }
 { v = x; x = x / 7 / 2; }
 { x = x * 7 + 6; v = x; }
 { x = x * 7 ^ 6; v = x; }
 { x = x - 8 + 6; v = x; }
 { x = x ^ 7 | 2; v = x; }
  (void) v;
  return 0;
}
