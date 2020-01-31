


void f ();
enum Sign { NEG=-1, ZERO, POS };

static inline enum Sign sign (double x)
{
  if (x > 0) return POS;
  if (x < 0) return NEG;
  return ZERO;
}
void g (double x)
{
  if (sign (x) == NEG) f();
}
