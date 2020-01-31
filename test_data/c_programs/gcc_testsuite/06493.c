





struct A {
  unsigned long long b : 8;
  unsigned long long c : 18;
};

int main()
{
  struct A a;
  long long l;

  l = a.c = 0x123456789aULL;
  return 0;
}
