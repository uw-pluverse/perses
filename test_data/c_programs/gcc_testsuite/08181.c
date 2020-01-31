







struct S {
  unsigned n;
};

inline void foo (struct S * mx) {
  mx->n = 1;
}

void bar () {
  foo (0);
}
