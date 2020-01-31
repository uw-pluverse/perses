






double atan(double);

struct s { double d; };
struct t { int i; };

void
f (void)
{

  struct s a = { atan (1.0) };

  struct t b = { 2147483647 + 1 };

  struct t c = { 1.7976931348623157e+308 };


  struct s d = { 1 ? 1.0 : atan (a.d) };
}
