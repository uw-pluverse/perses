enum A { B = -3, C = 2 } a;
_Bool b;

__attribute__((no_sanitize_undefined))
static void
vla_bound (void)
{
  int i = -1;
  volatile int a[i];
}

__attribute__((no_sanitize_undefined))
static void
si_overflow (void)
{
  int x = 123, y = 267;
  volatile int z1 = x + y;
  volatile int z2 = x - y;
  volatile int z3 = x * y;
  volatile int z4 = x / y;
}

__attribute__((no_sanitize_undefined))
static void
null (int *p)
{
  *p = 42;
}

__attribute__((no_sanitize_undefined))
static void
retrn (int *p)
{
  *p = 42;
}

__attribute__((no_sanitize_undefined))
static enum A
bool_enum (_Bool *p)
{
  *p = b;
  return a;
}

__attribute__((no_sanitize_undefined))
static void
float_zero (void)
{
  volatile float a = 4.2f, b = 0.0f, c;
  c = a / b;
}

__attribute__((no_sanitize_undefined))
static void
float_cast (void)
{
  volatile double d = 300;
  volatile signed char c;
  c = d;
}
