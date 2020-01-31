typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
extern int printf(const char *, ...);
extern int vprintf(const char *, va_list);
int CheckSimple() {
#pragma omp target
  {
    const char* fmt = "%d %lld %f";
    printf(fmt, 1, 2ll, 3.0);
  }
  return 0;
}
void CheckNoArgs() {
#pragma omp target
  {
    printf("hello, world!");
  }
}
int foo;
void CheckAllocaIsInEntryBlock() {
#pragma omp target
  {
    if (foo) {
      printf("%d", 42);
    }
  }
}
