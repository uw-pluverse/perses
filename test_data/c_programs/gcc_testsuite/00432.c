





extern int vfork(void);

void
boom (void)
{
  char buf[65536];
  vfork();
}
