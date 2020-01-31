typedef __attribute__(( ext_vector_type(4) )) float float4;
void test()
{
  float4 va;
  va.hi[0] = 3.0;
}
