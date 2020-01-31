


struct foo {
  char c;
  char d;
  short s;
  int i;
} bar;

int
sub1 (long long int foobar)
{
  struct foo *tmp = (struct foo *) &foobar;
  return tmp->i;
}
