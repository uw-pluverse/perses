






_Bool foo;


int a = 1;
int b = 0;
int c = 1;

struct foo
{
  _Bool a : 1;
} sf;





extern void abort (void);
extern void exit (int);
extern int strcmp (const char *, const char *);

int
main (void)
{

  const char *t = "_Bool";
  _Bool u, v;
  if (strcmp (t, "_Bool"))
    abort ();
  if (a != 1 || b != 0 || c != 1)
    abort ();

  if ((int)(_Bool)2 != 1)
    abort ();
  if ((int)(_Bool)0.2 != 1)
    abort ();

  if ((u = t) != 1)
    abort ();

  u = 0;
  if (t[u] != '_')
    abort ();
  if (u[t] != '_')
    abort ();
  u = 1;
  if (t[u] != 'B')
    abort ();
  if (u[t] != 'B')
    abort ();

  u = 0;
  if (u++ != 0)
    abort ();
  if (u != 1)
    abort ();
  if (u++ != 1)
    abort ();
  if (u != 1)
    abort ();
  u = 0;
  if (++u != 1)
    abort ();
  if (u != 1)
    abort ();
  if (++u != 1)
    abort ();
  if (u != 1)
    abort ();
  u = 0;
  if (u-- != 0)
    abort ();
  if (u != 1)
    abort ();
  if (u-- != 1)
    abort ();
  if (u != 0)
    abort ();
  u = 0;
  if (--u != 1)
    abort ();
  if (u != 1)
    abort ();
  if (--u != 0)
    abort ();
  if (u != 0)
    abort ();

  u = 0;
  if (+u != 0)
    abort ();
  if (-u != 0)
    abort ();
  u = 1;
  if (+u != 1)
    abort ();
  if (-u != -1)
    abort ();
  u = 2;
  if (+u != 1)
    abort ();
  if (-u != -1)
    abort ();
  u = 0;
  if (~u != ~(int)0)
    abort ();
  u = 1;
  if (~u != ~(int)1)
    abort ();
  u = 0;
  if (!u != 1)
    abort ();
  u = 1;
  if (!u != 0)
    abort ();

  u = 0;
  if (u + 2 != 2)
    abort ();
  u = 1;
  if (u * 4 != 4)
    abort ();
  if (u % 3 != 1)
    abort ();
  if (u / 1 != 1)
    abort ();
  if (4 / u != 4)
    abort ();
  if (u - 7 != -6)
    abort ();

  u = 1;
  if (u << 1 != 2)
    abort ();
  if (u >> 1 != 0)
    abort ();

  u = 0;
  v = 0;
  if (u < v || u > v || !(u <= v) || !(u >= v) || !(u == v) || u != v)
    abort ();
  u = 0;
  v = 1;
  if (!(u < v) || u > v || !(u <= v) || u >= v || u == v || !(u != v))
    abort ();

  u = 1;
  if ((u | 2) != 3)
    abort ();
  if ((u ^ 3) != 2)
    abort ();
  if ((u & 1) != 1)
    abort ();
  if ((u & 0) != 0)
    abort ();

  u = 0;
  v = 1;
  if (!(u || v))
    abort ();
  if (!(v || u))
    abort ();
  if (u && v)
    abort ();
  if (v && u)
    abort ();
  u = 1;
  v = 1;
  if (!(u && v))
    abort ();

  u = 0;
  if ((u ? 4 : 7) != 7)
    abort ();
  u = 1;
  v = 0;
  if ((1 ? u : v) != 1)
    abort ();
  if ((1 ? 4 : u) != 4)
    abort ();

  if ((u = 2) != 1)
    abort ();
  if (u != 1)
    abort ();
  if ((u *= -1) != 1)
    abort ();
  if (u != 1)
    abort ();
  if ((u /= 2) != 0)
    abort ();
  if ((u += 3) != 1)
    abort ();
  if ((u -= 1) != 0)
    abort ();
  u = 1;
  if ((u <<= 4) != 1)
    abort ();
  if ((u >>= 1) != 0)
    abort ();
  u = 1;
  if ((u &= 0) != 0)
    abort ();
  if ((u |= 2) != 1)
    abort ();
  if ((u ^= 3) != 1)
    abort ();

  u = 1;
  if ((4, u) != 1)
    abort ();

  {
    int i;
    for (i = 0; i < sizeof (struct foo); i++)
      *((unsigned char *)&sf + i) = (unsigned char) -1;
    sf.a = 1;
    if (sf.a != 1)
      abort ();
    sf.a = 0;
    if (sf.a != 0)
      abort ();
  }
  exit (0);
}
