extern void link_error(void);

extern int signbit(double);
extern int signbitf(float);
extern int signbitl(long double);

int main()
{
  if (signbit (1.0) != 0)
    link_error ();
  if (signbit (-2.0) == 0)
    link_error ();

  if (signbitf (1.0f) != 0)
    link_error ();
  if (signbitf (-2.0f) == 0)
    link_error ();

  if (signbitl (1.0l) != 0)
    link_error ();
  if (signbitl (-2.0f) == 0)
    link_error ();

  return 0;
}
