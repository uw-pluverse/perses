



int i;

void
foo ()
{
#pragma omp parallel
 {
    int j;
    i = j;
  }
}
