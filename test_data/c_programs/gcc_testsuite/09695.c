


int tp1;
static int tp2;
extern int tp3;

int tp4 = 1;
static int tp5 = 1;

#pragma omp threadprivate (tp1, tp2, tp3, tp4, tp5)

#pragma omp threadprivate (undef)

int tp6;
int foo(void) { return tp6; }

#pragma omp threadprivate (tp6)

