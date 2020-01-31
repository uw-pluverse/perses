






extern void foo () __attribute__((weak,visibility("hidden")));
int
main()
{
  if (foo)
    foo ();
  return 0;
}
