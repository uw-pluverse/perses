struct foo;
void b;
struct foo f;
static void c;
static struct foo g;
extern void d;
extern struct foo e;
int ary[];
struct foo bary[];
void func() {
  int ary[];
  void b;
  struct foo f;
}
int h[];
int (*i)[] = &h+1;
struct bar j = {1};
struct bar k;
struct bar { int a; };
