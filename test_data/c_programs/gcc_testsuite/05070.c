


typedef struct { int i; } Foo;
Foo foo;
Foo *bar(void)
{
  return (Foo *)&foo.i;
}
