






extern void a (void) __attribute__((weak_import));
extern void b (void) __attribute__((weak_import));

void b(void)
{
  a();
}
