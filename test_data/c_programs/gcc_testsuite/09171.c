



void (* volatile fn) (void);
static void foo (void)
{
}

int main (void)
{
  fn = foo;
  return 0;
}
