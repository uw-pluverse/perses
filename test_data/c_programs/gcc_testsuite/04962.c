





typedef __attribute__((warn_unused_result)) int (*fnt) (void);

typedef struct { long i; } A;
typedef struct { long i; long j; } B;
typedef struct { char big[1024]; fnt fn; } C;

__attribute__((warn_unused_result)) int check1 (void);
__attribute__((warn_unused_result)) void check2 (void);
int foo __attribute__((warn_unused_result));
int bar (void);
extern __attribute__((warn_unused_result, always_inline)) inline int check3 (void) { return bar (); }
__attribute__((warn_unused_result)) A check4 (void);
__attribute__((warn_unused_result)) B check5 (void);
__attribute__((warn_unused_result)) C check6 (void);
A bar7 (void);
B bar8 (void);
C bar9 (void);
extern __attribute__((warn_unused_result, always_inline)) inline A check7 (void) { return bar7 (); }
extern __attribute__((warn_unused_result, always_inline)) inline B check8 (void) { return bar8 (); }
extern __attribute__((warn_unused_result, always_inline)) inline C check9 (void) { return bar9 (); }


extern __attribute__((warn_unused_result, always_inline)) inline int check_int_result (int res) { return res; }

fnt fnptr;
__attribute__((warn_unused_result)) int check10 (void);
int baz (void);
extern __attribute__((warn_unused_result, always_inline)) inline int check11 (void) { return baz (); }
int k;

void
test (void)
{
  int i = 0, j;
  const fnt pcheck1 = check1;
  const fnt pcheck3 = check3;
  A a;
  B b;
  C c;
  if (check1 ())
    return;
  i += check1 ();
  i += ({ check1 (); });
  check1 ();
  (void) check1 ();
  check1 (), bar ();
  check2 ();
  (void) check2 ();
  check2 (), bar ();
  if (check3 ())
    return;
  i += check3 ();
  i += ({ check3 (); });
  check3 ();
  (void) check3 ();
  check3 (), bar ();
  a = check4 ();
  if (a.i)
    return;
  if (check4 ().i)
    return;
  if (({ check4 (); }).i)
    return;
  check4 ();
  (void) check4 ();
  check4 (), bar ();
  b = check5 ();
  if (b.i + b.j)
    return;
  if (check5 ().j)
    return;
  if (({ check5 (); }).j)
    return;
  check5 ();
  (void) check5 ();
  check5 (), bar ();
  c = check6 ();
  if (c.big[12] + c.big[29])
    return;
  if (check6 ().big[27])
    return;
  if (({ check6 (); }).big[0])
    return;
  check6 ();
  (void) check6 ();
  check6 (), bar ();
  a = check7 ();
  if (a.i)
    return;
  if (check7 ().i)
    return;
  if (({ check7 (); }).i)
    return;
  check7 ();
  (void) check7 ();
  check7 (), bar ();
  b = check8 ();
  if (b.i + b.j)
    return;
  if (check8 ().j)
    return;
  if (({ check8 (); }).j)
    return;
  check8 ();
  (void) check8 ();
  check8 (), bar ();
  c = check9 ();
  if (c.big[12] + c.big[29])
    return;
  if (check9 ().big[27])
    return;
  if (({ check9 (); }).big[0])
    return;
  check9 ();
  (void) check9 ();
  check9 (), bar ();
  if (check_int_result (({ int e = 0; (j) = bar (); if ((j) < 23) e = 14; e; })))
    return;
  i += check_int_result (({ int e = 0; (j) = bar (); if ((j) < 23) e = 14; e; }));
  i += ({ check_int_result (({ int e = 0; (j) = bar (); if ((j) < 23) e = 14; e; })); });
  check_int_result (({ int e = 0; (j) = bar (); if ((j) < 23) e = 14; e; }));
  (void) check_int_result (({ int e = 0; (j) = bar (); if ((j) < 23) e = 14; e; }));
  check_int_result (({ int e = 0; (j) = bar (); if ((j) < 23) e = 14; e; })), bar ();
  if (fnptr ())
    return;
  i += fnptr ();
  i += ({ fnptr (); });
  fnptr ();
  (void) fnptr ();
  fnptr (), bar ();
  fnptr = check1;
  if (fnptr ())
    return;
  i += fnptr ();
  i += ({ fnptr (); });
  fnptr ();
  (void) fnptr ();
  fnptr (), bar ();
  fnptr = check3;
  if (fnptr ())
    return;
  i += fnptr ();
  i += ({ fnptr (); });
  fnptr ();
  (void) fnptr ();
  fnptr (), bar ();
  if (bar9 ().fn ())
    return;
  i += bar9 ().fn ();
  i += ({ bar9 ().fn (); });
  bar9 ().fn ();
  (void) bar9 ().fn ();
  bar9 ().fn (), bar ();
  if ((k ? check1 : check10) ())
    return;
  i += (k ? check1 : check10) ();
  i += ({ (k ? check1 : check10) (); });
  (k ? check1 : check10) ();
  (void) (k ? check1 : check10) ();
  (k ? check1 : check10) (), bar ();
  if ((k ? check3 : check11) ())
    return;
  i += (k ? check3 : check11) ();
  i += ({ (k ? check3 : check11) (); });
  (k ? check3 : check11) ();
  (void) (k ? check3 : check11) ();
  (k ? check3 : check11) (), bar ();
  if (pcheck1 ())
    return;
  i += pcheck1 ();
  i += ({ pcheck1 (); });
  pcheck1 ();
  (void) pcheck1 ();
  pcheck1 (), bar ();
  if (pcheck3 ())
    return;
  i += pcheck3 ();
  i += ({ pcheck3 (); });
  pcheck3 ();
  (void) pcheck3 ();
  pcheck3 (), bar ();
}
