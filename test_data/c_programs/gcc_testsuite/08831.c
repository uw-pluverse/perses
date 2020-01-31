



enum E1 { A };
enum E2 { B };
extern void foo_E (enum E1);
extern void foo_v (void *p);
extern void foo_sc (int, int, signed char *);
extern unsigned char *uc;
extern signed char sc;
extern const signed char *csc;
extern float *f;

void
foo (void)
{
  void (*fp)(void);
  const void (*ffp)(void);
  foo_v (fp);
  foo_E (B);
  foo_sc (1, 2, uc);
  foo_sc (1, 2, f);
  foo_sc (1, 2, sc);
  foo_sc (uc, 2, &sc);
  foo_sc (1, 2, csc);
}

typedef void (*fp)(void);
typedef void (*nrfp)(void) __attribute__((noreturn));
void f1 (nrfp); void f2 (fp x) { f1 (x); } extern int e;
