


int global;

int f2()
{
  return __transaction_atomic (global + 3)
         + __transaction_atomic (global + 4);
}
