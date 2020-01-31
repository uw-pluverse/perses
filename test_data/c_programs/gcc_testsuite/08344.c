#pragma GCC visibility push(hidden)
#pragma GCC visibility push(default)
extern void* memcpy (void *, const void *, long unsigned int);
#pragma GCC visibility pop

struct a { int a[4096]; };

extern void *bar (struct a *, struct a *, int);

void *
foo (struct a *a, struct a *b, int c)
{
  struct a cc = *b;
  return bar (a, &cc, 4 * c);
}
