__attribute__((format(printf, 1, 2)))
extern int printf(const char *fmt, ...);
void test1(Unknown* b);
void test2(Unknown* b);
void test3() {
                                                                                                   printf("%d", "s");
}
