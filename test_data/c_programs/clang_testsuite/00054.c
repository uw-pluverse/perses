int var;
void err_eq(int x) {
  var = 77 / x;
  if (x == 0) { }
}
void err_eq2(int x) {
  var = 77 / x;
  if (0 == x) { }
}
void err_ne(int x) {
  var = 77 / x;
  if (x != 0) { }
}
void err_ge(int x) {
  var = 77 / x;
  if (x >= 0) { }
}
void err_le(int x) {
  var = 77 / x;
  if (x <= 0) {}
}
void err_yes(int x) {
  var = 77 / x;
  if (x) {}
}
void err_not(int x) {
  var = 77 / x;
  if (!x) {}
}
void err_pnot(int x) {
  int *y = &x;
  var = 77 / *y;
  if (!x) {}
}
void err_pnot2(int x) {
  int *y = &x;
  var = 77 / x;
  if (!*y) {}
}
void err_ppnot(int x) {
  int *y = &x;
  int **z = &y;
  var = 77 / **z;
  if (!x) {}
}
void err_orig_checker(int x) {
  if (x != 0)
    return;
  var = 77 / x;
  if (!x) {}
}
void ok_other(int x, int y) {
  var = 77 / y;
  if (x == 0) {
  }
}
void ok_assign(int x) {
  var = 77 / x;
  x = var / 77;
  if (x == 0) {
  }
}
void ok_assign2(int x) {
  var = 77 / x;
  x = var / 77;
  if (0 == x) {
  }
}
void ok_dec(int x) {
  var = 77 / x;
  x--;
  if (x == 0) {
  }
}
void ok_inc(int x) {
  var = 77 / x;
  x++;
  if (x == 0) {
  }
}
void do_something_ptr(int *x);
void ok_callfunc_ptr(int x) {
  var = 77 / x;
  do_something_ptr(&x);
  if (x == 0) {
  }
}
void do_something(int x);
void nok_callfunc(int x) {
  var = 77 / x;
  do_something(x);
  if (x == 0) {}
}
void ok_if(int x) {
  if (x > 3)
    var = 77 / x;
  if (x == 0) {
  }
}
void ok_if2(int x) {
  if (x < 3)
    var = 77 / x;
  if (x == 0) {
  }
}
void ok_pif(int x) {
  int *y = &x;
  if (x < 3)
    var = 77 / *y;
  if (x == 0) {
  }
}
int getValue(bool *isPositive);
void use(int a);
void foo() {
  bool isPositive;
  int x = getValue(&isPositive);
  if (isPositive) {
    use(5 / x);
  }
  if (x == 0) {
  }
}
int getValue2();
void foo2() {
  int x = getValue2();
  int y = x;
  use(5 / x);
  if (y == 0) {}
}
void ok_while(int x) {
  int n = 100 / x;
  while (x != 0) {
    x--;
  }
}
void err_not2(int x, int y) {
  int v;
  var = 77 / x;
  if (y)
    v = 0;
  if (!x) {
  }
}
inline void inline_func(int x) {
  var = 77 / x;
  if (x == 0) {}
}
void err_inline(int x) {
  var = 77 / x;
  inline_func(x);
  if (x == 0) {
  }
}
inline void inline_func2(int x) {}
void err_inline2(int x) {
  var = 77 / x;
  inline_func2(x);
  if (x == 0) {}
}
inline void inline_func3(int x) {
  var = 77 / x;
}
void ok_inline(int x) {
  var = 77 / x;
  inline_func3(x);
  if (x == 0) {}
}
