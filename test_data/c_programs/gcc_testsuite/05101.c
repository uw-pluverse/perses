






typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void foo (int, va_list);
extern void bar (int);
long x;
va_list gap;


void
f1 (int i, ...)
{
  __builtin_va_start(gap, i);
  x = __builtin_va_arg(gap, long);
  __builtin_va_end(gap);
}
void
f2 (int i, ...)
{
  __builtin_va_start(gap, i);
  bar (i);
  __builtin_va_end(gap);
}
void
f3 (int i, ...)
{
  va_list aps[10];
  __builtin_va_start(aps[4], i);
  x = __builtin_va_arg(aps[4], long);
  __builtin_va_end(aps[4]);
}
void
f4 (int i, ...)
{
  va_list aps[10];
  __builtin_va_start(aps[4], i);
  bar (i);
  __builtin_va_end(aps[4]);
}
void
f5 (int i, ...)
{
  va_list aps[10];
  __builtin_va_start(aps[4], i);
  foo (i, aps[4]);
  __builtin_va_end(aps[4]);
}
struct A { int i; va_list g; va_list h[2]; };

void
f6 (int i, ...)
{
  struct A a;
  __builtin_va_start(a.g, i);
  x = __builtin_va_arg(a.g, long);
  __builtin_va_end(a.g);
}
void
f7 (int i, ...)
{
  struct A a;
  __builtin_va_start(a.g, i);
  bar (i);
  __builtin_va_end(a.g);
}
void
f8 (int i, ...)
{
  struct A a;
  __builtin_va_start(a.g, i);
  foo (i, a.g);
  __builtin_va_end(a.g);
}
void
f10 (int i, ...)
{
  struct A a;
  __builtin_va_start(a.h[1], i);
  x = __builtin_va_arg(a.h[1], long);
  __builtin_va_end(a.h[1]);
}
void
f11 (int i, ...)
{
  struct A a;
  __builtin_va_start(a.h[1], i);
  bar (i);
  __builtin_va_end(a.h[1]);
}
void
f12 (int i, ...)
{
  struct A a;
  __builtin_va_start(a.h[1], i);
  foo (i, a.h[1]);
  __builtin_va_end(a.h[1]);
}
