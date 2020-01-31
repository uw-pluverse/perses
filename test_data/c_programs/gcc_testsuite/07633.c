




void bar (char *p, char *q);

int main()
{
  char foo [32], *p;

  ({
    void *s = (foo);
    __builtin_memset (s, '\0', sizeof (foo));
    s;
    s;
  });
  p = foo;
  p;
  bar (foo, p);
  return 0;
}
