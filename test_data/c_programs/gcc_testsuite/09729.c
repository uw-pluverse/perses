


extern void bar (void);

int main (void)
{
#pragma omp parallel sections nowait
 {
#pragma omp section
 { bar(); }
#pragma omp section
 { bar(); }
    }
}
