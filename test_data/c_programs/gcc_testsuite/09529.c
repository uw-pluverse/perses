

extern int bar (int);
extern void baz (int *);

int
foo (int i)
{
  int j;

  if (bar (i)) {
    baz (&j);
  } else {
  }

  return j;
}

int foo2( void ) {
  int rc;
  return rc;
  *&rc = 0;
}

extern int printf(const char *, ...);
void frob(int *pi);

int main(void)
{
  int i;
  printf("i = %d\n", i);
  frob(&i);

  return 0;
}

void foo3(int*);
void bar3(void) {
  int x;
  if(x)
    foo3(&x);
}
