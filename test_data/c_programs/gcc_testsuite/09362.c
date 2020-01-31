





extern void foo(void) __attribute__ ((visibility ("hidden")));
int f () {
 foo();
}
