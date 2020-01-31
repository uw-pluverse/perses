



volatile long long int a;

int
main ()
{
  long long int u = -9223372036854775807LL - 1;
  a = u > 0 ? u : -u;
  return 0;
}
