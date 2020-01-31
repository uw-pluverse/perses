




typedef long long int64_t;
typedef int64_t int64x1_t __attribute__ ((__vector_size__ (8)));



int64_t
test_eon (int64_t a, int64_t b)
{
  return a ^ ~b;
}


int64_t
test_not (int64_t a)
{
  return ~a;
}





int64x1_t
test_vec_eon (int64x1_t a, int64x1_t b)
{
  return a ^ ~b;
}

int64x1_t
test_vec_not (int64x1_t a)
{
  return ~a;
}
