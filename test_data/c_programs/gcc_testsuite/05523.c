


void link_error (void);

typedef struct {
  int x;
  int z;
} Foo_t;

char *xm;
void bar(void);

void foo(void)
{
  Foo_t x;
  x.x = 1;
  x.z = 2;
  xm = (char *)&x;
  bar();

  if (x.z != 2)
    link_error ();
}
