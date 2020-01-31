





extern void abort(void);
extern void exit(int);

int main(void)
{
  long double l1 = 1.9999999999999999991326382620115964527941L;
  long double l2 = 2.0000000000000000008673617379884035472059L;
  long double l3 = -2.0000000000000000008673617379884035472059L;
  long double l4 = -1.9999999999999999991326382620115964527941L;

  if ((int) l1 != 1)
    abort ();
  if ((int) l2 != 2)
    abort ();
  if ((int) l3 != -2)
    abort ();
  if ((int) l4 != -1)
    abort ();
  exit (0);
}
