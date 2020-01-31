


static struct s {
  int x;
  char y;
} s;

void set (char c)
{
  s.y = c;
}


char get (void)
{
  return s.y;
}
