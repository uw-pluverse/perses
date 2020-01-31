

extern void abort (void);
extern void exit (int);

__attribute__ ((externally_visible)) int global;
int func(void);


int bad0(void) { return __builtin_constant_p(global); }
int bad1(void) { return __builtin_constant_p(global++); }
inline int bad2(int x) { return __builtin_constant_p(x++); }
inline int bad3(int x) { return __builtin_constant_p(x); }
inline int bad4(const char *x) { return __builtin_constant_p(x); }
int bad5(void) { return bad2(1); }
inline int bad6(int x) { return __builtin_constant_p(x+1); }
int bad7(void) { return __builtin_constant_p(func()); }
int bad8(void) { char buf[10]; return __builtin_constant_p(buf); }
int bad9(const char *x) { return __builtin_constant_p(x[123456]); }
int bad10(void) { return __builtin_constant_p(&global); }


int good0(void) { return __builtin_constant_p(1); }
int good1(void) { return __builtin_constant_p("hi"); }
int good2(void) { return __builtin_constant_p((1234 + 45) & ~7); }



int opt0(void) { return bad3(1); }
int opt1(void) { return bad6(1); }
int opt2(void) { return __builtin_constant_p("hi"[0]); }
int (* volatile bad_t0[])(void) = {
 bad0, bad1, bad5, bad7, bad8, bad10
};

int (* volatile bad_t1[])(int x) = {
 bad2, bad3, bad6
};

int (* volatile bad_t2[])(const char *x) = {
 bad4, bad9
};

int (* volatile good_t0[])(void) = {
 good0, good1, good2
};

int (* volatile opt_t0[])(void) = {
 opt0, opt1, opt2
};



int main()
{
  int i;

  for (i = 0; i < (sizeof(bad_t0)/sizeof(*bad_t0)); ++i)
    if ((*bad_t0[i])())
      abort();

  for (i = 0; i < (sizeof(bad_t1)/sizeof(*bad_t1)); ++i)
    if ((*bad_t1[i])(1))
      abort();

  for (i = 0; i < (sizeof(bad_t2)/sizeof(*bad_t2)); ++i)
    if ((*bad_t2[i])("hi"))
      abort();

  for (i = 0; i < (sizeof(good_t0)/sizeof(*good_t0)); ++i)
    if (! (*good_t0[i])())
      abort();







  exit(0);
}
