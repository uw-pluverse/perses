





extern void foo_i (int);
extern void foo_f (float);
extern void foo_ld (long double);
extern void foo_cd (__complex__ double);

extern int i;
extern float f;
extern long double ld;
extern __complex__ double cd;

void
testfunc1 ()
{
  foo_i (i);
  foo_i (f);
  foo_i (ld);
  foo_i (cd);

  foo_f (i);
  foo_f (f);
  foo_f (ld);
  foo_f (cd);

  foo_ld (i);
  foo_ld (f);
  foo_ld (ld);
  foo_ld (cd);

  foo_cd (i);
  foo_cd (f);
  foo_cd (ld);
  foo_cd (cd);
}


void
testfunc2 ()
{
  foo_i (i);
  foo_i (f);
  foo_i (ld);
  foo_i (cd);

  foo_f (i);
  foo_f (f);
  foo_f (ld);
  foo_f (cd);

  foo_ld (i);
  foo_ld (f);
  foo_ld (ld);
  foo_ld (cd);

  foo_cd (i);
  foo_cd (f);
  foo_cd (ld);
  foo_cd (cd);
}
