float testf (float x, int sel1, int sel2) { float input = sel1 ? -x : x + 1; if (sel2) return __builtin_cosf (input); else return __builtin_coshf (input); }
double test (double x, int sel1, int sel2) { double input = sel1 ? -x : x + 1; if (sel2) return __builtin_cos (input); else return __builtin_cosh (input); }
long double testl (long double x, int sel1, int sel2) { long double input = sel1 ? -x : x + 1; if (sel2) return __builtin_cosl (input); else return __builtin_coshl (input); }
