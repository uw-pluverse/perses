


int test (int a, int b, int sum)
{
  sum += ((a - b) > 0 ? (a - b) : -(a - b));
  return sum;
}
