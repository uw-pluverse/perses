

struct S { int c, *b, *e; };

void
foo ()
{
  struct S a;
  asm volatile ("" : "=rm" (a) : "0" (1));
}
