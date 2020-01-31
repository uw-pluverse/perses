





struct s { char c[1]; };
struct s a, b, c;
int d;

void
bar (void)
{
  char *t;
  (d ? b : c).c[0];
  (d, b).c[0];
  (a = b).c[0];
  t = (d ? b : c).c;
  t = (d, b).c;
  t = (a = b).c;
  (d ? b : c).c + 1;
  (d, b).c + 1;
  (a = b).c + 1;
}
