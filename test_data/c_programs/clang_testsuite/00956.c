typedef short v2i16 __attribute__((vector_size (4)));
typedef short v3i16 __attribute__((vector_size (6)));
typedef short v4i16 __attribute__((vector_size (8)));
typedef short v6i16 __attribute__((vector_size (12)));
typedef short v8i16 __attribute__((vector_size (16)));
typedef short v16i16 __attribute__((vector_size (32)));
struct v16i16 { v16i16 x; };
v2i16 test_v2i16(v2i16 x)
{
  return x;
}
v3i16 test_v3i16(v3i16 x)
{
  return x;
}
v4i16 test_v4i16(v4i16 x)
{
  return x;
}
v6i16 test_v6i16(v6i16 x)
{
  return x;
}
v8i16 test_v8i16(v8i16 x)
{
  return x;
}
v16i16 test_v16i16(v16i16 x)
{
  return x;
}
struct v16i16 test_struct_v16i16(struct v16i16 x)
{
  return x;
}
