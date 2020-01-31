extern void abort();




struct tree_type
{
  unsigned int precision : 9;
};

int
sign_bit_p (struct tree_type *t, long val_hi, unsigned long val_lo)
{
  unsigned long mask_lo, lo;
  long mask_hi, hi;
  int width = t->precision;

  if (width > (sizeof(long)*8))
    {
      hi = (unsigned long) 1 << (width - (sizeof(long)*8) - 1);
      lo = 0;

      mask_hi = ((unsigned long) -1
                 >> (2 * (sizeof(long)*8) - width));
      mask_lo = -1;
    }
  else
    {
      hi = 0;
      lo = (unsigned long) 1 << (width - 1);

      mask_hi = 0;
      mask_lo = ((unsigned long) -1
                 >> ((sizeof(long)*8) - width));
    }

  if ((val_hi & mask_hi) == hi
      && (val_lo & mask_lo) == lo)
    return 1;

  return 0;
}

int main()
{
  struct tree_type t;
  t.precision = 1;
  if (!sign_bit_p (&t, 0, -1))
    abort ();
  return 0;
}
