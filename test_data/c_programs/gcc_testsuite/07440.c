


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

struct mystr
{
  int f1;
  int f2;
};

struct mystr a[16];
struct mystr b[16];
int res1, res2;


void
foo (void)
{
  int i;
  int sum1 = 0;
  int sum2 = 0;

  for (i = 0; i < 16; i++)
  {
    sum1 += a[i].f1 + b[i].f1;
    sum2 += a[i].f2 + b[i].f2;
  }

  res1 = sum1;
  res2 = sum2;
}
