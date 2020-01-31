

long long
emacs_lseek (long long offset)
{
  return -1-9223372036854775807LL <= offset && offset <= 9223372036854775807LL;
}

long long
foo (long long offset)
{
  return -1-9223372036854775807LL > offset && offset > 9223372036854775807LL;
}

long long
foo3 (long long offset)
{
  return -1-9223372036854775807LL > offset && offset < 9223372036854775807LL;
}

long long
foo2 (long long offset)
{
  if (-1-9223372036854775807LL <= offset) return 0;
  if (offset <= 9223372036854775807LL) return 0;
  if (-1-9223372036854775807LL > offset) return 0;
  if (offset > 9223372036854775807LL) return 0;
  return 1;
}




long long get_intmax(void);
int get_int(void);
extern void do_something(void);
int main(void)
{
   int i = get_int();
   long long x = get_intmax();
   i = (i > (-2147483647 -1) && i < 2147483647);
   i = (i >= (-2147483647 -1)+1 && i <= 2147483647 -1);
   i = (i >= (-2147483647 -1) && i <= 2147483647);
}
