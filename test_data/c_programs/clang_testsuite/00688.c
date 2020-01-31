void test0(int *x, int y) {
}
void test1(int * restrict x, int y) {
}
void test2(int *x, int * restrict y) {
}
typedef int * restrict rp;
void test3(rp x, int y) {
}
void test4(int *x, rp y) {
}
