


void foo(char *p1, char **p2)
{}

int main(void)
{
  char str[] = "foo { xx }";
  char *ptr = str + 5;

  foo(ptr, &ptr);

  while (*ptr && (*ptr == 13 || *ptr == 32))
    ptr++;

  return 0;
}
