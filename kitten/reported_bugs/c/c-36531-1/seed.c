




typedef unsigned __int128 u128;
typedef unsigned __int128 V __attribute__ ((vector_size (64)));

V
foo (u128 a, u128 b, u128 c, V d)
{
  V e = (V) {a};
  V f = e & 1;
  e = 0 != e;
  c = c;
  f = f << ((V) {c} & 7);
  return f + e;
}
