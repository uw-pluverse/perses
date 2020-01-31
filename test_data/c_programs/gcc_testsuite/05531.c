


typedef int intflt;






intflt b;
void f(void)
{
  float a;
  a = 1;
  b = *(intflt*)&a;
}
