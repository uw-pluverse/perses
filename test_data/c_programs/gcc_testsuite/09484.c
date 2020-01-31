







void
f (void)
{
  void *p = &&a;
  goto *p;
 a: ;
}
