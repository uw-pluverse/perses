struct P1 {
    struct Q1 {
      char a[6];
      char b[6];
    } q;
};
struct P1 l1 = {
    (struct Q1){ "foo", "bar" },
               .q.b = { "boo" },
               .q.b = { [1] = 'x' }
};
struct P1 l1a = {
    (struct Q1){ "foo", "bar" },
               .q.b = { "boo" },
               .q.b[1] = 'x'
};
struct P2 { char x[6]; };
struct P2 l2 = {
  .x = { [1] = 'o' },
  .x = { [0] = 'n' }
};
struct P3 {
    struct Q3 {
      struct R1 {
         int a, b, c;
      } r1;
      struct R2 {
         int d, e, f;
      } r2;
    } q;
};
struct P3 l3 = {
  (struct Q3){ { 1, 2, 3 }, { 4, 5, 6 } },
                    .q.r2 = { 7, 8, 9 },
                    .q.r2 = { .e = 10 }
};
typedef int wchar_t;
struct P4 {
    wchar_t x[6];
};
struct P4 l4 = { { L"foo" }, .x[2] = L'x' };
struct P5 {
  int x;
  struct Q5 {
    int a, b, c;
  } q;
  int y;
};
struct P5 l5 = { 1, { 2, 3, 4 }, 5,
                 .q = { 6, 7, 8 },
                 .q.b = 9 };
