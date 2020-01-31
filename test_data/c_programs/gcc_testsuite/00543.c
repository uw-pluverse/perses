




struct Test {
  double D __attribute__((packed,aligned(4)));
  short X;
} x;

struct {
  char x;
  struct Test t;
} b = { 1, { 2, 3 } };
