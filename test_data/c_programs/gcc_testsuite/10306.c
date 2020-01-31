


char *vx;
char buf[20];

void
foo (void)
{
  vx = __builtin___stpcpy_chk (buf, vx ? "gh" : "e", sizeof(buf));
}
