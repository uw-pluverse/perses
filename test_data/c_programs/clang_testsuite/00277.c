typedef int T0;
typedef struct { int a[16]; } T1;
T0 __attribute__((const)) f0(void);
T0 __attribute__((pure)) f1(void);
T1 __attribute__((const)) f2(void);
T1 __attribute__((pure)) f3(void);
void __attribute__((const)) f4(T1 a);
void __attribute__((pure)) f5(T1 a);
void *ps[] = { f0, f1, f2, f3, f4, f5 };
