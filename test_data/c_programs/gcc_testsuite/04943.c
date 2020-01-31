



extern void bar (void);

void
fn (void *p)
{
  void *a = p + 1;
  void (*a2)(void) = &bar + 1;
}
