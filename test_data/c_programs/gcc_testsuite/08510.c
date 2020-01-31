




typedef struct cpp_num cpp_num;
struct cpp_num
{
  long high;
  long low;
  char overflow;
};



static cpp_num
num_equality_op (lhs, rhs)
     cpp_num lhs, rhs;
{
  lhs.low = (lhs.low == rhs.low && lhs.high == rhs.high);
  lhs.high = 0;
  lhs.overflow = 0;
  return lhs;
}

int main()
{
  cpp_num a = { 1, 2 };
  cpp_num b = { 3, 4 };

  cpp_num result = num_equality_op (a, b);
  if (result.low)
    return 1;

  result = num_equality_op (a, a);
  if (!result.low)
    return 2;

  return 0;
}
