


void *
foo (void)
{
lab:
  return &&lab;


}

void *
bar (void)
{
  __label__ lab;
lab:
  return &&lab;


}

void *
baz (void)
{
  int i;
  return &i;


}
