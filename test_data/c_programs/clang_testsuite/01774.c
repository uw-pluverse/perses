void clang_analyzer_eval(int);
void f1() {
  int a[10];
  int *p = a;
  ++p;
}
char* foo();
void f2() {
  char *p = foo();
  ++p;
}
void* memchr();
static int
domain_port (const char *domain_b, const char *domain_e,
             const char **domain_e_ptr)
{
  int port = 0;
  const char *p;
  const char *colon = memchr (domain_b, ':', domain_e - domain_b);
  for (p = colon + 1; p < domain_e ; p++)
    port = 10 * port + (*p - '0');
  return port;
}
void f3() {
  int x, y;
  int d = &y - &x;
  int a[10];
  int *p = &a[2];
  int *q = &a[8];
  d = q-p;
}
void f4() {
  int *p;
  p = (int*) 0x10000;
}
void f5() {
  int x, y;
  int *p;
  p = &x + 1;
  int a[10];
  p = a + 1;
}
void f6(int *p, int *q) {
  int d = q - p;
}
void null_operand(int *a) {
start:
  clang_analyzer_eval(&&start != 0);
  clang_analyzer_eval(&&start >= 0);
  clang_analyzer_eval(&&start > 0);
  clang_analyzer_eval((&&start - 0) != 0);
  clang_analyzer_eval(&a != 0);
  clang_analyzer_eval(&a >= 0);
  clang_analyzer_eval(&a > 0);
  clang_analyzer_eval((&a - 0) != 0);
  clang_analyzer_eval(0 != &a);
  clang_analyzer_eval(0 <= &a);
  clang_analyzer_eval(0 < &a);
  clang_analyzer_eval(a != 0);
  clang_analyzer_eval(a >= 0);
  clang_analyzer_eval(a <= 0);
  clang_analyzer_eval((a - 0) != 0);
  clang_analyzer_eval(0 != a);
  clang_analyzer_eval(0 <= a);
  clang_analyzer_eval(0 < a);
}
void const_locs() {
  char *a = (char*)0x1000;
  char *b = (char*)0x1100;
start:
  clang_analyzer_eval(a != b);
  clang_analyzer_eval(a < b);
  clang_analyzer_eval(a <= b);
  clang_analyzer_eval((b-a) == 0x100);
  clang_analyzer_eval(&&start == a);
  clang_analyzer_eval(a == &&start);
  clang_analyzer_eval(&a == (char**)a);
  clang_analyzer_eval((char**)a == &a);
}
void array_matching_types() {
  int array[10];
  int *a = &array[2];
  int *b = &array[5];
  clang_analyzer_eval(a != b);
  clang_analyzer_eval(a < b);
  clang_analyzer_eval(a <= b);
  clang_analyzer_eval((b-a) != 0);
}
void array_different_types() {
  int array[10];
  int *a = &array[2];
  char *b = (char*)&array[5];
  clang_analyzer_eval(a != b);
  clang_analyzer_eval(a < b);
  clang_analyzer_eval(a <= b);
}
struct test { int x; int y; };
void struct_fields() {
  struct test a, b;
  clang_analyzer_eval(&a.x != &a.y);
  clang_analyzer_eval(&a.x < &a.y);
  clang_analyzer_eval(&a.x <= &a.y);
  clang_analyzer_eval(&a.x != &b.x);
  clang_analyzer_eval(&a.x > &b.x);
  clang_analyzer_eval(&a.x >= &b.x);
}
void mixed_region_types() {
  struct test s;
  int array[2];
  void *a = &array, *b = &s;
  clang_analyzer_eval(&a != &b);
  clang_analyzer_eval(&a > &b);
  clang_analyzer_eval(&a >= &b);
}
void symbolic_region(int *p) {
  int a;
  clang_analyzer_eval(&a != p);
  clang_analyzer_eval(&a > p);
  clang_analyzer_eval(&a >= p);
}
void PR7527 (int *p) {
  if (((int) p) & 1)
    return;
}
void use_symbols(int *lhs, int *rhs) {
  clang_analyzer_eval(lhs < rhs);
  if (lhs < rhs)
    return;
  clang_analyzer_eval(lhs < rhs);
  clang_analyzer_eval(lhs - rhs);
  if ((lhs - rhs) != 5)
    return;
  clang_analyzer_eval((lhs - rhs) == 5);
}
void equal_implies_zero(int *lhs, int *rhs) {
  clang_analyzer_eval(lhs == rhs);
  if (lhs == rhs) {
    clang_analyzer_eval(lhs != rhs);
    clang_analyzer_eval((rhs - lhs) == 0);
    return;
  }
  clang_analyzer_eval(lhs == rhs);
  clang_analyzer_eval(lhs != rhs);
  clang_analyzer_eval((rhs - lhs) == 0);
}
void zero_implies_equal(int *lhs, int *rhs) {
  clang_analyzer_eval((rhs - lhs) == 0);
  if ((rhs - lhs) == 0) {
    clang_analyzer_eval(lhs != rhs);
    clang_analyzer_eval(lhs == rhs);
    return;
  }
  clang_analyzer_eval((rhs - lhs) == 0);
  clang_analyzer_eval(lhs == rhs);
  clang_analyzer_eval(lhs != rhs);
}
void comparisons_imply_size(int *lhs, int *rhs) {
  clang_analyzer_eval(lhs <= rhs);
  if (lhs > rhs) {
    clang_analyzer_eval((rhs - lhs) == 0);
    return;
  }
  clang_analyzer_eval(lhs <= rhs);
  clang_analyzer_eval((rhs - lhs) >= 0);
  clang_analyzer_eval((rhs - lhs) > 0);
  if (lhs >= rhs) {
    clang_analyzer_eval((rhs - lhs) == 0);
    return;
  }
  clang_analyzer_eval(lhs == rhs);
  clang_analyzer_eval(lhs < rhs);
  clang_analyzer_eval((rhs - lhs) > 0);
}
void size_implies_comparison(int *lhs, int *rhs) {
  clang_analyzer_eval(lhs <= rhs);
  if ((rhs - lhs) < 0) {
    clang_analyzer_eval(lhs == rhs);
    return;
  }
  clang_analyzer_eval(lhs <= rhs);
  clang_analyzer_eval((rhs - lhs) >= 0);
  clang_analyzer_eval((rhs - lhs) > 0);
  if ((rhs - lhs) <= 0) {
    clang_analyzer_eval(lhs == rhs);
    return;
  }
  clang_analyzer_eval(lhs == rhs);
  clang_analyzer_eval(lhs < rhs);
  clang_analyzer_eval((rhs - lhs) > 0);
}
void zero_implies_reversed_equal(int *lhs, int *rhs) {
  clang_analyzer_eval((rhs - lhs) == 0);
  if ((rhs - lhs) == 0) {
    clang_analyzer_eval(rhs != lhs);
    clang_analyzer_eval(rhs == lhs);
    return;
  }
  clang_analyzer_eval((rhs - lhs) == 0);
  clang_analyzer_eval(rhs == lhs);
  clang_analyzer_eval(rhs != lhs);
}
void canonical_equal(int *lhs, int *rhs) {
  clang_analyzer_eval(lhs == rhs);
  if (lhs == rhs) {
    clang_analyzer_eval(rhs == lhs);
    return;
  }
  clang_analyzer_eval(lhs == rhs);
  clang_analyzer_eval(rhs == lhs);
}
void compare_element_region_and_base(int *p) {
  int *q = p - 1;
  clang_analyzer_eval(p == q);
}
struct Point {
  int x;
  int y;
};
void symbolicFieldRegion(struct Point *points, int i, int j) {
  clang_analyzer_eval(&points[i].x == &points[j].x);
  clang_analyzer_eval(&points[i].x == &points[i].y);
  clang_analyzer_eval(&points[i].x < &points[i].y);
}
void negativeIndex(char *str) {
  *(str + 1) = 'a';
  clang_analyzer_eval(*(str + 1) == 'a');
  clang_analyzer_eval(*(str - 1) == 'a');
  char *ptr1 = str - 1;
  clang_analyzer_eval(*ptr1 == 'a');
  char *ptr2 = str;
  ptr2 -= 1;
  clang_analyzer_eval(*ptr2 == 'a');
  char *ptr3 = str;
  --ptr3;
  clang_analyzer_eval(*ptr3 == 'a');
}
