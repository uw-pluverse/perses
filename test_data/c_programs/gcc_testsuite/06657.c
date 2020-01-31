static int a = 0;
extern int foo (void);
extern int *bar (void) __attribute__ ((__const__));

void
test (int x)
{
  int b = 10;
  while (foo () == -1 && *bar () == 4 && b > 0)
    --b;
  a = x;
}
