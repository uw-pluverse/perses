


extern double log (double x);
extern int f (void);

double cached_value;

void g (void)
{
  cached_value = log (f ());
}
