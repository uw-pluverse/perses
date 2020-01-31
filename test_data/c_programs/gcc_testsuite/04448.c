



void
fn0 (void)
{
}
extern void __attribute__((optimize ("O2"))) fn0 (void);

extern __attribute__((noinline)) int fn1 (void);
extern inline int fn1 (void);

extern inline int fn2 (void);
extern __attribute__((noinline)) int fn2 (void);

extern __attribute__((always_inline)) int fn3 (void);
extern __attribute__((noinline)) int fn3 (void);

extern __attribute__((noinline)) int fn4 (void);
extern __attribute__((always_inline)) int fn4 (void);

extern __attribute__((hot)) int fn5 (void);
extern __attribute__((cold)) int fn5 (void);

extern __attribute__((cold)) int fn6 (void);
extern __attribute__((hot)) int fn6 (void);
