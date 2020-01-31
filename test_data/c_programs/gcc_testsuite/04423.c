

union {
  char *p;
  double d;
} u;

void
f (void)
{
  u.p = "";
  u.d += 1.1;
}
