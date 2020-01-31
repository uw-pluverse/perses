static void foo(void) {}
void bar(void) __attribute__((alias("foo")))
__attribute__((visibility("hidden")));
