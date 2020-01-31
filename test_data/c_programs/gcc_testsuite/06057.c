




int z;
int y;

int * foo(int a) __attribute__((returns_nonnull));
int * bar(void) __attribute__((returns_nonnull));

int *
foo(int a)

{
  switch (a)
    {
      case 0:
        return &z;
      default:
        return (int *)0;
    }
}


int *
bar (void)
{
  return 0;
}
