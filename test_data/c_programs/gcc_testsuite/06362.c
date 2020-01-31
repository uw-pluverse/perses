


void bar() {}

int t106_1mul(unsigned int x, unsigned int y) {
    int r;
    if (__builtin_mul_overflow(x, y, &r)) {
        bar();
    }
    return r;
}
