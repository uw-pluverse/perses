





typedef int T;
typedef int T __attribute__((aligned (64)));
typedef int T __attribute__((aligned (64 * 2)));
typedef int T __attribute__((aligned (64)));
typedef int T;

_Static_assert (_Alignof (T) == 64 * 2, "N * 2");
