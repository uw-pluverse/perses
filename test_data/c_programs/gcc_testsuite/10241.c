


int foo;

__attribute__((transaction_callable))
void cloneme()
{
  foo = 666;
}
