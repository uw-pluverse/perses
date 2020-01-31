

void foo()
{
#pragma omp master
 {
      goto bad1;
    }

#pragma omp master
 {
    bad1:
      return;
    }
}
