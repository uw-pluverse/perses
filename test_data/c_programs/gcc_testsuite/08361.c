typedef int noinline_type __attribute__((noinline));

typedef int (*noinline_fntype)(void) __attribute__((noinline));

struct noinline_struct {
  char dummy __attribute__((noinline));
} __attribute__((noinline));

int noinline_var __attribute__((noinline));

int noinline_fn_knrarg (arg)
  int arg __attribute__((noinline));
{ return 0; }

int noinline_fn_isoarg (int arg __attribute__((noinline))) { return 0; }

int noinline_fn_vars (void) {
  static int svar __attribute__((noinline));
  auto int lvar __attribute__((noinline));
  return 0;
}





typedef int used_type __attribute__((used));


typedef int (*used_fntype)(void) __attribute__((used));


struct used_struct {
  char dummy __attribute__((used));
} __attribute__((used));

int used_var __attribute__((used));

int used_fn_knrarg (arg)
  int arg __attribute__((used));
{ return 0; }

int used_fn_isoarg (int arg __attribute__((used))) { return 0; }

int used_fn_vars (void) {
  static int svar __attribute__((used));
  auto int lvar __attribute__((used));
  return 0;
}
typedef int weak_type __attribute__((weak));

typedef int (*weak_fntype)(void) __attribute__((weak));

struct weak_struct {
  char dummy __attribute__((weak));
};

int weak_fn_knrarg (arg)
  int arg __attribute__((weak));
{ return 0; }

int weak_fn_isoarg (int arg __attribute__((weak))) { return 0; }
typedef int dllimport_type __attribute__((dllimport));

typedef int (*dllimport_fntype)(void) __attribute__((dllimport));

struct dllimport_struct {
  char dummy __attribute__((dllimport));
};

int dllimport_fn_knrarg (arg)
  int arg __attribute__((dllimport));
{ return 0; }

int dllimport_fn_isoarg (int arg __attribute__((dllimport))) { return 0; }
