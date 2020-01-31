static int sa[100];

volatile int nv;

int
f (int m, int n)
{
  static int (*a1)[n] = &sa;
  static int (*a2)[n] = (int (*)[n])sa;
  static int (*a3)[n] = (int (*)[(int){n}])sa;
  static int (*a4)[n] = (int (*)[(int){m++}])sa;
  static int (*a5)[n] = (int (*)[(int){++m}])sa;
  static int (*a6)[n] = (int (*)[(int){m--}])sa;
  static int (*a7)[n] = (int (*)[(int){--m}])sa;
  static int (*a8)[n] = (int (*)[(m=n)])sa;
  static int (*a9)[n] = (int (*)[(m+=n)])sa;
  static int (*a10)[n] = (int (*)[f(m,n)])sa;
  static int (*a11)[n] = (int (*)[(m,n)])sa;
  static int (*a12)[n] = (int (*)[sizeof(int[n])])sa;
  static int (*a13)[n] = (int (*)[sizeof(int[m++])])sa;
  static int (*a14)[n] = (int (*)[sizeof(*a1)])sa;
  static int (*a15)[n] = (int (*)[sizeof(*(int (*)[n])sa)])sa;
  static int (*a16)[n] = (int (*)[sizeof(*(int (*)[m++])sa)])sa;
  static int (*a17)[n] = (int (*)[nv])sa;
  typedef int (*vmt)[m++];
  static int (*a18)[n] = (vmt)sa;
  return n;
}
