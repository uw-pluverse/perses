int nan_ne_check() {
  return (__builtin_nanf("") != __builtin_nanf("")) ? 1 : 0;
}
