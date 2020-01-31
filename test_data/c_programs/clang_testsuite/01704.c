void foo(const char *, ...) __attribute__((__format__ (__printf__, 1, 2)));
void bar(unsigned int a) {
        foo("%s", a);
}
