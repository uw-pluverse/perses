



typedef char v32qi  __attribute__ ((vector_size (32)));
typedef unsigned char v32uqi  __attribute__ ((vector_size (32)));

__attribute__((noipa)) v32qi
foo_ashiftrt_256 (v32qi a)
{
  return a >> 2;
}




__attribute__((noipa)) v32qi
foo_ashift_256 (v32qi a)
{
  return a << 7;
}



__attribute__((noipa)) v32uqi
foo_lshiftrt_256 (v32uqi a)
{
  return a >> 2;
}
