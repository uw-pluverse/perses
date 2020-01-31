double cabs(_Complex double);
double __attribute__((used)) __attribute__ ((optimize ("O2,fast-math")))
foo (_Complex double x, int b)
{
  if (b)
    x = 0;
  return cabs(x);
}

int main() { return 0; }
