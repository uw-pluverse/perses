






typedef union {
  double val;
  struct {
    unsigned int w1;
    unsigned int w2;
  };
} words;

unsigned int f (double d)
{
  words u;
  u.val = d;
  return u.w2;
}
