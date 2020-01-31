union u { int i; unsigned : 3; };
void f(union u);
void test(int x) {
  f((union u)x);
  f((union u)&x);
  f((union u)2U);
}
union u w = (union u)2;
union u ww = (union u)1.0;
union u x = 7;
int i;
union u zz = (union u)i;
struct s {int a, b;};
struct s y = { 1, 5 };
struct s z = (struct s){ 1, 5 };
