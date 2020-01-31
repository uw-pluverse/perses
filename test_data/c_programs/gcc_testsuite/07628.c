





struct S { float f1; int i1; int i2; float f2; };

extern void foo(struct S);

void bar(void)
{
  struct S s;
  foo(s);
}
