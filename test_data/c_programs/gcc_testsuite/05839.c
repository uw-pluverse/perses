


int foo(void)
{
  int i = 0;
  char *p = (char *)&i;
  return *(int *)p;
}

struct Foo {
  int i;
} f;

int bar(void)
{
  char *p = (char *)&f;
  return ((struct Foo *)p)->i;
}

extern const struct Foo g;

int foobar(void)
{
  struct Foo *p = (struct Foo *)&g;
  return ((const struct Foo *)p)->i;
}
