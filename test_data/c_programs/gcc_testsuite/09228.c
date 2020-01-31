extern int bar (void);

void
foo (void)
{
  int i;
  static int j = (1 ? 0 : (i = 2));
  static int k = (1 ? 0 : ++i);
  static int l = (1 ? 0 : --i);
  static int m = (1 ? 0 : bar ());
  static int n = (1 ? 0 : (2, 3));
}
