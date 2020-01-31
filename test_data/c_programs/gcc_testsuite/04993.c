






float vf(int i)
{
  register __attribute__((vector_size(16) )) float a;
  return a[0];
}
