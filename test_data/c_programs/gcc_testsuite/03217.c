


typedef union
{
  double d;
  long long ll;
} A;

void
foo (A x, A **y, A z)
{
  for (; *y; y++)
    if (x.ll == 262 && (*y)->d == z.d)
      break;
}
