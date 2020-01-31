





static int __thread foo;

int *
bar (void)
{
  return &foo;
}
