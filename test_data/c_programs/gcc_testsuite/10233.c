


static int x;

void __attribute__((transaction_callable))
foo(void)
{
  x++;
}
