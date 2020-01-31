

void e(int);
__attribute__ ((always_inline)) inline int
t(int function_parameter)
{
  e(function_parameter);
}

void test (int function_parameter2)
{
  t(function_parameter2);
}
