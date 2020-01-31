






struct s { char c[1]; };

extern struct s foo(void);

void bar(void)
{
  char *ptr = foo().c;
}
