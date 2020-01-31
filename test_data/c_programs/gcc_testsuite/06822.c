


typedef unsigned long long uint64_t;


double A[4096][4096] __attribute__((aligned(16)));
double B[4096][4096] __attribute__((aligned(16)));
double C[4096][4096] __attribute__((aligned(16)));



typedef double adouble __attribute__((__aligned__(16)));

void foo ()
{
  int ih, jh, kh, il, kl, jl;
  for (ih = 0; ih < 4096; ih += 128)
    for (jh = 0; jh < 4096; jh += 128)
      for (kh = 0; kh < 4096; kh += 128)
 for (il = 0; il < 128; ++il)
   {
     adouble *Ap = (adouble *)&A[ih+il][kh];
     for (kl = 0; kl < 128; ++kl)
       for (jl = 0; jl < 128; ++jl)
  C[ih+il][jh+jl] += Ap[kl] * B[kh+kl][jh+jl];
   }
}
