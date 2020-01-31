typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
struct test1 { int x; int y; };
struct test2 { int x; int y; } __attribute__((aligned (16)));
struct test3 { int x; int y; } __attribute__((aligned (32)));
struct test4 { int x; int y; int z; };
struct test5 { int x[17]; };
struct test6 { int x[17]; } __attribute__((aligned (16)));
struct test7 { int x[17]; } __attribute__((aligned (32)));
void test1 (int x, struct test1 y)
{
}
void test2 (int x, struct test2 y)
{
}
void test3 (int x, struct test3 y)
{
}
void test4 (int x, struct test4 y)
{
}
void test5 (int x, struct test5 y)
{
}
void test6 (int x, struct test6 y)
{
}
void test7 (int x, struct test7 y)
{
}
struct test1 test1va (int x, ...)
{
  struct test1 y;
  va_list ap;
  __builtin_va_start(ap,x);
  y = __builtin_va_arg(ap,struct test1);
  __builtin_va_end(ap);
  return y;
}
struct test2 test2va (int x, ...)
{
  struct test2 y;
  va_list ap;
  __builtin_va_start(ap,x);
  y = __builtin_va_arg(ap,struct test2);
  __builtin_va_end(ap);
  return y;
}
struct test3 test3va (int x, ...)
{
  struct test3 y;
  va_list ap;
  __builtin_va_start(ap,x);
  y = __builtin_va_arg(ap,struct test3);
  __builtin_va_end(ap);
  return y;
}
struct test4 test4va (int x, ...)
{
  struct test4 y;
  va_list ap;
  __builtin_va_start(ap,x);
  y = __builtin_va_arg(ap,struct test4);
  __builtin_va_end(ap);
  return y;
}
struct test_longdouble { long double x; };
struct test_longdouble testva_longdouble (int x, ...)
{
  struct test_longdouble y;
  va_list ap;
  __builtin_va_start(ap,x);
  y = __builtin_va_arg(ap,struct test_longdouble);
  __builtin_va_end(ap);
  return y;
}
struct test_vector { vector int x; };
struct test_vector testva_vector (int x, ...)
{
  struct test_vector y;
  va_list ap;
  __builtin_va_start(ap,x);
  y = __builtin_va_arg(ap,struct test_vector);
  __builtin_va_end(ap);
  return y;
}
