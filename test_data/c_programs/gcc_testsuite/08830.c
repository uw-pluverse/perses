




extern void abort ();

int t __attribute__((section("__TEST,__test")));

int main (void)
{

  if ((unsigned long long) &t != 0x110000000ULL)



    abort ();
  return 0;
}
