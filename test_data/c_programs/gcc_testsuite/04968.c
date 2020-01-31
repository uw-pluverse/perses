






extern void f1(void) __attribute__((transaction_callable));
extern void f2(void) __attribute__((transaction_unsafe));
extern void f3(void) __attribute__((transaction_pure));
extern void f4(void) __attribute__((transaction_safe));

extern void g1(void) __attribute__((transaction_callable)) __attribute__((transaction_safe));

extern int v1 __attribute__((transaction_pure));

typedef void t1(void) __attribute__((transaction_callable));
typedef void (*t2)(void) __attribute__((transaction_callable));
typedef int t3 __attribute__((transaction_callable));

typedef void u0(void);
typedef u0 u1 __attribute__((transaction_callable));
typedef u1 u2 __attribute__((transaction_pure));
typedef u0 *u3 __attribute__((transaction_safe));
typedef u3 u4 __attribute__((transaction_unsafe));
