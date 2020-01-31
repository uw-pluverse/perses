


void __attribute__((noreturn)) bar(void)
{
}

void foo(int i, char *p, char *q)
{
  while (*p++) {
      if (i)
 p++;
      if (!*q++)
 bar();
  }
}
