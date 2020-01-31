



struct S { char **a; };

void
test (void)
{
  struct S b = { .a = (char **) { "a", "b" } };
  struct S c = { .a = (char *[]) { "a", "b" } };
}
