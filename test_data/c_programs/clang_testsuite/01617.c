int a __attribute__((returns_twice));
__attribute__((returns_twice)) void t0(void) {
}
void t1() __attribute__((returns_twice));
void t2() __attribute__((returns_twice(2)));
typedef void (*t3)(void) __attribute__((returns_twice));
