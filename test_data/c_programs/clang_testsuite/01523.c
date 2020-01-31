void check(int);
void a() {
  check(__builtin_isfinite(1.0f));
  check(__builtin_isinf(1.0));
  check(__builtin_isinf_sign(1.0L));
  check(__builtin_isnan(1.0f));
  check(__builtin_isnormal(1.0f));
  check(__builtin_isfinite(1));
  check(__builtin_isinf());
  check(__builtin_isnan(1,2));
  check(__builtin_fpclassify(0, 0, 0, 0, 0, 1.0));
  check(__builtin_fpclassify(0, 0, 0, 0, 0, 1));
  check(__builtin_fpclassify(0, 1, 2, 3, 4.5, 5.0));
  check(__builtin_fpclassify(0, 0, 0, 0, 1));
  check(__builtin_fpclassify(0, 0, 0, 0, 0, 1, 0));
}
