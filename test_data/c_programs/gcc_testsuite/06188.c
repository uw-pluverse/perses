




enum E1 { A };
enum E2 { B };

struct S
{
  enum E1 e: 3;
};

struct S s[] =
{
  { B }
};

union U {
  int i;
  long long int l;
};

struct R {
  int a;
};

void
foo (int i)
{
  union U u = { .i = ++i, .l = 1 };
  union U u2 = { .i = 1, .l = 3 };
  int a[] = { i++, [0] = 1 };
  int a2[] = { i, [0] = 1 };
  struct R r = { 1, .a = 2 };
  struct R r2 = { ++i, .a = 2 };
}
