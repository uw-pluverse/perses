




volatile int g_k;
extern void bar(int, int, int, int);

int foo(int a, int b, int c, int d)
{
  if (g_k & 4) c++;
  bar (a, b, c, d);
  return 0;
}
