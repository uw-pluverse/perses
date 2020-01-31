


extern int bar (int);

__attribute__((no_caller_saved_registers))
void
foo (void)
{
  int a,b,c,d,e,f,i;
  a = bar (5);
  b = bar (a);
  c = bar (b);
  d = bar (c);
  e = bar (d);
  f = bar (e);
  for (i = 1; i < 10; i++)
  {
    a += bar (a + i) + bar (b + i) +
  bar (c + i) + bar (d + i) +
  bar (e + i) + bar (f + i);
  }
}
