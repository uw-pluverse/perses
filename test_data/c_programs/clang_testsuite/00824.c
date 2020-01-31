typedef struct { int v; } Agg;
Agg makeAgg(void);
void test0() {
  __block Agg a = {100};
 a = makeAgg();
}
void test1() {
  __block Agg a, b;
  a = b = makeAgg();
}
