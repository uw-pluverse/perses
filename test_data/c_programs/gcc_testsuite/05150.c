


extern void link_error(void);

void test1 (int i, int j, int b)
{
  if (i < 2 || i > 6) return;;
  if (j >= 1 && j <= 7) return;;
  if (b) i = j;;
  do { __typeof__ (i) v = (i); if (v >= 1) if (v <= 1) link_error(); if (v >= 1 && v <= 1) link_error(); } while (0);
}
int main() { }
