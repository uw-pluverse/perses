






extern char *strdup (const char *);

void
func(char *a, char *b, char *c)
{
  strdup(a);
  strdup(b);
  strdup(c);
}

int
main(void)
{
  func("a", "b", "c");
  return 0;
}
