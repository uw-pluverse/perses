extern void abort (void);
extern void exit (int);

typedef struct { char c[(256*1024)/2]; } big_t;

typedef int __attribute__((mode(SI))) __attribute__((vector_size (8))) vecint;
typedef int __attribute__((mode(SI))) siint;

vecint i = { 150, 100 };
vecint j = { 10, 13 };
vecint k;

union {
  vecint v;
  siint i[2];
} res;

void
verify (siint a1, siint a2, siint b1, siint b2, big_t big)
{
  if (a1 != b1
      || a2 != b2)
    abort ();
}

int
main ()
{
  big_t big;
  vecint k0, k1, k2, k3, k4, k5, k6, k7;

  k0 = i + j;
  res.v = k0;

  verify (res.i[0], res.i[1], 160, 113, big);

  k1 = i * j;
  res.v = k1;

  verify (res.i[0], res.i[1], 1500, 1300, big);

  k2 = i / j;
  res.v = k2;

  verify (res.i[0], res.i[1], 15, 7, big);

  k3 = i & j;
  res.v = k3;

  verify (res.i[0], res.i[1], 2, 4, big);

  k4 = i | j;
  res.v = k4;

  verify (res.i[0], res.i[1], 158, 109, big);

  k5 = i ^ j;
  res.v = k5;

  verify (res.i[0], res.i[1], 156, 105, big);

  k6 = -i;
  res.v = k6;
  verify (res.i[0], res.i[1], -150, -100, big);

  k7 = ~i;
  res.v = k7;
  verify (res.i[0], res.i[1], -151, -101, big);

  k = k0 + k1 + k3 + k4 + k5 + k6 + k7;
  res.v = k;
  verify (res.i[0], res.i[1], 1675, 1430, big);

  k = k0 * k1 * k3 * k4 * k5 * k6 * k7;
  res.v = k;
  verify (res.i[0], res.i[1], 1456467968, -1579586240, big);

  k = k0 / k1 / k2 / k3 / k4 / k5 / k6 / k7;
  res.v = k;
  verify (res.i[0], res.i[1], 0, 0, big);

  exit (0);
}
