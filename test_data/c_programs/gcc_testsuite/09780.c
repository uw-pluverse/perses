int *a;
int b;
long *c;
void
foo (void)
{
  (b = *(1 ? a : (0)));
  (b = *(1 ? a : ((void *)0)));
  (c = (1 ? a : ((void *)(void *)0)));
  (c = (1 ? a : ((void *)(char *)0)));
  (c = (1 ? a : ((void *)(0, 0L))));
  (c = (1 ? a : ((void *)(&"Foobar"[0] - &"Foobar"[0]))));

  (b = *(1 ? a : ((void *)(1 ? 0 : (0, 0)))));
}
