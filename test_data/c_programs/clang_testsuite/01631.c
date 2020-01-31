typedef struct S1 {
  union {
    struct S2 *x;
    struct S3 *y;
  } u1;
} S1;
int test_struct_scope(S1 *s1, struct S2 *s2, struct S3 *s3) {
  if (s1->u1.x == s2) return 1;
  if (s1->u1.y == s3) return 1;
  return 0;
}
int test_struct_scope_2(S1 *s1) {
  struct S2 { int x; } *s2 = 0;
  if (s1->u1.x == s2) return 1;
  return 0;
}
int test_struct_scope_3(struct S4 * s4) {
  struct S4 { int y; } *s4_2 = 0;
  return 0;
}
void f(struct S5 { int y; } s5);
struct S6 {
        enum { BAR } e;
};
void test_S6() {
        struct S6 a;
        a.e = BAR;
}
typedef struct z_foo_s {
  struct bar_baz *baz;
} z_foo;
typedef z_foo *z_foop;
struct bar_baz {
  enum {
    SQUAT, FLAG, DICT4, DICT3, DICT2, DICT1, DICT0, HOP, CHECK4, CHECK3, CHECK2, CHECK1, DONE, BAD
  } mode;
  int nowrap;
};
void
wizbiz_quxPoof(z)
  z_foop z;
{
  z->baz->mode = z->baz->nowrap ? HOP : SQUAT;
}
