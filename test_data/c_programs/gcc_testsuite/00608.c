

typedef short vec16 __attribute__((vector_size(8)));
typedef int vec32 __attribute__((vector_size(8)));

vec16 fun16(vec16 a, vec16 b)
{
  return (~a & b) + (b | a) - (a ^ b);
}

vec32 fun32(vec32 a, vec32 b)
{
  return (~a & b) + (b | a) - (a ^ b);
}


vec16 fun16b(vec16 a, vec16 b)
{
  return (a & ~b) + (b | a) - (a ^ b);
}

vec32 fun32b(vec32 a, vec32 b)
{
  return (a & ~b) + (b | a) - (a ^ b);
}
