


extern int long_call_func () __attribute__((long_call));
extern int far_func () __attribute__((far));
extern int near_func () __attribute__((near));
extern int normal_func ();

int test ()
{
  return (long_call_func ()
          + far_func ()
          + near_func ()
          + normal_func ());
}
