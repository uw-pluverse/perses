





void a(int*); void b(int*); void c(int*); void d(int*);
void func2(int* val)
{
  const void *const labels[] = { &&a, &&b, &&c, &&d };
  goto *labels[2];
  a: a(val);
  b: b(val);
  c: c(val);
  d: d(val);
}
