


struct S { unsigned long long int b:40; } s;

int
main ()
{
  s.b = 2;
  s.b <<= 120;
  return 0;
}
