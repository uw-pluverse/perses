


extern void abort(void);

void decCompareOp (int result)
{
  if (result != (int) (2147483647 + 1U))
    {
      result = -result;
      if (result != (int) (2147483647 + 2U))
        abort ();
    }
}

int main()
{
  decCompareOp (2147483647);
  return 0;
}
