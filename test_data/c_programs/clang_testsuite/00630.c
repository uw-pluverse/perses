typedef struct S {
  int a;
  int b;
} S;
void test_addrspace(__attribute__((address_space(1))) S* p1, __attribute__((address_space(2))) S*p2) {
  p1->a = p2->b;
  p1->b = p2->a;
}
