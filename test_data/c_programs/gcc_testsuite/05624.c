


void start (void *);
void end (void *);
void testf (float *array, float y, int n) { for (;;) { start (array); float x = -__builtin_fabsf (array[-1]); for (int i = 0; i < n; ++i) x = -x / array[i]; array[-1] = x * x; array[-2] = __builtin_fmaf (x, x, y); array[-3] = __builtin_powf (x, 20); end (array); } }
void test (double *array, double y, int n) { for (;;) { start (array); double x = -__builtin_fabs (array[-1]); for (int i = 0; i < n; ++i) x = -x / array[i]; array[-1] = x * x; array[-2] = __builtin_fma (x, x, y); array[-3] = __builtin_pow (x, 20); end (array); } }
void testl (long double *array, long double y, int n) { for (;;) { start (array); long double x = -__builtin_fabsl (array[-1]); for (int i = 0; i < n; ++i) x = -x / array[i]; array[-1] = x * x; array[-2] = __builtin_fmal (x, x, y); array[-3] = __builtin_powl (x, 20); end (array); } }
