extern long return_long (void);
extern double return_double (void);

double return_double2 (void)
{
  return (double) return_long ();
}

long return_long2 (void)
{
  return (long) return_double ();
}
