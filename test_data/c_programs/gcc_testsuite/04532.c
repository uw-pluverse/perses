






struct test_struct {
  unsigned long a;
  int b;
} __attribute__((__aligned__(64)));

char a[200];

int main ()
{
  volatile int x = ((struct test_struct*)((((((unsigned long)a)-1) | ((__typeof__((unsigned long)a))((64)-1)))+1) + 16))->b;
  volatile int y = ((struct test_struct*)((((((unsigned long)a)-1) | ((__typeof__((unsigned long)a))((64)-1)))+1) + 15))->b;

  return 0;
}
