



extern void __morestack_fail (const char *msg);
void
foo (void)
{
  static const char msg[] = "munmap of stack space failed: errno ";
  __morestack_fail (msg);
}
