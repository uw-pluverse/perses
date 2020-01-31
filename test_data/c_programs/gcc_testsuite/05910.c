float testf (float x, float y, float *array, int n) { x = __builtin_copysignf (x, y); for (int i = 0; i < n; ++i) x *= -array[i]; return __builtin_hypotf (x, y); }
double test (double x, double y, double *array, int n) { x = __builtin_copysign (x, y); for (int i = 0; i < n; ++i) x *= -array[i]; return __builtin_hypot (x, y); }
long double testl (long double x, long double y, long double *array, int n) { x = __builtin_copysignl (x, y); for (int i = 0; i < n; ++i) x *= -array[i]; return __builtin_hypotl (x, y); }
