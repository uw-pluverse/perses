







typedef void foo;
foo bar(void);
void baz(void)
{
  bar();
}

void volatile f();

int x()
{
  f();
}
