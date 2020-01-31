


extern void abort (void);
typedef float vf128 __attribute__((vector_size(16)));
typedef float vf64 __attribute__((vector_size(8)));
int main()
{


  vf128 v = (vf128){ 0.f, 0.f, 0.f, 0.f };
  vf64 u = (vf64){ 0.f, 0.f };
  v = v / (vf128){ 0.f, 0.f, 0.f, 0.f };
  if (v[0] == v[0])
    abort ();
  u = u / (vf64){ 0.f, 0.f };
  if (u[0] == u[0])
    abort ();


  return 0;
}
