extern void foo(int a);
void test(unsigned a) {
  switch (a) {
    a += 5;
  case 2:
    a *= 10;
  case 3:
    a %= 2;
  }
  foo(a);
}
void test2(unsigned a) {
 help:
  if (a > 0)
    return;
  if (a == 0)
    return;
  foo(a);
  goto help;
}
void test3(unsigned a) {
  while(1);
  if (a > 5) {
    return;
  }
}
void test4() {
  int a = 5;
  while (a > 1)
    a -= 2;
  if (a > 1) {
    a = a + 56;
  }
  foo(a);
}
extern void bar(char c);
void test5(const char *c) {
  foo(c[0]);
  if (!c) {
    bar(1);
  }
}
void test6(const char *c) {
  if (c) return;
  if (!c) return;
  __builtin_unreachable();
}
enum test_enum { Off, On };
void test7() {
  if (0)
    return;
  if (sizeof(int))
    return;
  if (Off)
    return;
}
void test8() {
  static unsigned a = 0;
  if (a)
    a = 123;
  a = 5;
}
void test9(unsigned a) {
  switch (a) {
    if (a)
      foo(a + 5);
    else
      foo(a);
    case 1:
    case 2:
      break;
    default:
      break;
  }
}
void test10() {
  goto c;
  d:
  goto e;
  c: ;
  int i;
  return;
  goto b;
  goto a;
  b:
  i = 1;
  a:
  i = 2;
  goto f;
  e:
  goto d;
  f: ;
}
enum foobar { FOO, BAR };
extern void error();
void test11(enum foobar fb) {
  switch (fb) {
    case FOO:
      break;
    case BAR:
      break;
    default:
      error();
      return;
      error();
  }
}
void inlined(int condition) {
  if (condition) {
    foo(5);
  } else {
    foo(6);
  }
}
void testInlined() {
  extern int coin();
  int cond = coin();
  if (!cond) {
    inlined(0);
    if (cond) {
      foo(5);
    }
  }
}
void dostuff(int*A);
void varDecl1(int X) {
  switch (X) {
    int A;
  case 1:
    dostuff(&A);
    break;
  case 2:
    dostuff(&A);
    break;
  }
}
void varDecl2(int X) {
  switch (X) {
    int A=1;
  case 1:
    dostuff(&A);
    break;
  case 2:
    dostuff(&A);
    break;
  }
}
void test12(int x) {
  switch (x) {
  case 1:
    break;
  case 2:
    do { } while (0);
    break;
  }
}
extern int table[];
static int inlineFunction(const int i) {
  if (table[i] != 0)
    return 1;
  return 0;
}
void test13(int i) {
  int x = inlineFunction(i);
  x && x < 10;
}
void macro(void) {
  do { return; } while (0);
}
