void clang_analyzer_warnIfReached();
void f1(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index + 1 == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f2(unsigned long foo)
{
  int index = -1;
  if (index < foo) index = foo;
  if (index + 1 == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f3(unsigned long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index + 1 == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f4(long foo)
{
  int index = -1;
  if (index < foo) index = foo;
  if (index + 1 == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f5(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index == -1)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f6(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index == -1)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f7(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index - 1 == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f8(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index + 1L == 0L)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f9(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index - 1L == 0L)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f10(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index + 1 == 0L)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f11(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index + 1UL == 0L)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f12(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  if (index - 1UL == 0L)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f13(int foo)
{
  unsigned short index = -1;
  if (index < foo) index = foo;
  if (index + 1 == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f14(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  long bar = foo;
  if (index + 1 == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
void f15(long foo)
{
  unsigned index = -1;
  if (index < foo) index = foo;
  unsigned int tmp = index + 1;
  if (tmp == 0)
    clang_analyzer_warnIfReached();
  else
    clang_analyzer_warnIfReached();
}
