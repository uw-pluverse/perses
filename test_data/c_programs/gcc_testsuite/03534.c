





unsigned foo(unsigned x) {
  return __builtin_constant_p(x) ? 0 : ({ unsigned tmp=x; tmp; });
}
