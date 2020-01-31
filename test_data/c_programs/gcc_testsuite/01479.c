



typedef unsigned int u32;
u32
read32 (const void* ptr)
{
  u32 v;
  __builtin_memcpy (&v, ptr, sizeof(v));
  return v;
}
