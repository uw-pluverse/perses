

struct S;
#pragma omp declare reduction (+:struct S:omp_out.s += omp_in.s)
struct S { int s; };
#pragma omp declare reduction (*:struct S:omp_out.s *= omp_in.s)

