







void f ()
{
  { short v __attribute__((vector_size(16))); (void)((v < v) < v); }
  { int v __attribute__((vector_size(16))); (void)((v < v) < v); }
  { long v __attribute__((vector_size(16))); (void)((v < v) < v); }
  { long long v __attribute__((vector_size(16))); (void)((v < v) < v); }







}
