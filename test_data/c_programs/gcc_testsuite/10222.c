


void f(int *i)
{
 if (!i)
  return;
 else
 {
  __builtin_printf("Hi");
  *i=0;
 }
}
