struct _MyS {
  int foo;
} MyS;
struct _MyS ww;
int x, y;
typedef union {
  struct {
    int field : 16;
  };
} r_t;
void test() {
  r_t reg;
  reg.field = 1;
}
