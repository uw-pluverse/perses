


void
f1 (void)
{
  int i, j;
#pragma omp for
 for (i = 0; i < 3; i++)
    {
#pragma omp for
 for (j = 0; j < 3; j++)
 ;
#pragma omp sections
 {
 ;
#pragma omp section
 ;
      }
#pragma omp single
 ;
#pragma omp master
 ;
#pragma omp barrier
 }
#pragma omp sections
 {
#pragma omp for
 for (j = 0; j < 3; j++)
      ;
  }
#pragma omp sections
 {
#pragma omp sections
 {
      ;
#pragma omp section
 ;
    }
  }
#pragma omp sections
 {
#pragma omp single
 ;
  }
#pragma omp sections
 {
#pragma omp master
 ;
  }
#pragma omp sections
 {
#pragma omp section
 ;
  }
#pragma omp sections
 {
#pragma omp section
#pragma omp for
 for (j = 0; j < 3; j++)
      ;
  }
#pragma omp sections
 {
#pragma omp section
#pragma omp sections
 {
      ;
#pragma omp section
 ;
    }
  }
#pragma omp sections
 {
#pragma omp section
#pragma omp single
 ;
  }
#pragma omp sections
 {
#pragma omp section
#pragma omp master
 ;
  }
#pragma omp single
 {
#pragma omp for
 for (j = 0; j < 3; j++)
      ;
#pragma omp sections
 {
      ;
#pragma omp section
 ;
    }
#pragma omp single
 ;
#pragma omp master
 ;
#pragma omp barrier
 }
#pragma omp master
 {
#pragma omp for
 for (j = 0; j < 3; j++)
      ;
#pragma omp sections
 {
      ;
#pragma omp section
 ;
    }
#pragma omp single
 ;
#pragma omp master
 ;
#pragma omp barrier
 }
#pragma omp task
 {
#pragma omp for
 for (j = 0; j < 3; j++)
      ;
#pragma omp sections
 {
      ;
#pragma omp section
 ;
    }
#pragma omp single
 ;
#pragma omp master
 ;
#pragma omp barrier
 }
#pragma omp parallel
 {
#pragma omp for
 for (j = 0; j < 3; j++)
      ;
#pragma omp sections
 {
      ;
#pragma omp section
 ;
    }
#pragma omp single
 ;
#pragma omp master
 ;
#pragma omp barrier
 }
}

void
f2 (void)
{
  int i, j;
#pragma omp ordered
 {
#pragma omp for
 for (j = 0; j < 3; j++)
      ;
#pragma omp sections
 {
      ;
#pragma omp section
 ;
    }
#pragma omp single
 ;
#pragma omp master
 ;
#pragma omp barrier
 }
}

void
f3 (void)
{
#pragma omp critical
 {
#pragma omp ordered
 ;
  }
}

void
f4 (void)
{
#pragma omp task
 {
#pragma omp ordered
 ;
  }
}

void
f5 (void)
{
  int i;
#pragma omp for
 for (i = 0; i < 10; i++)
    {
#pragma omp ordered
 ;
    }
#pragma omp for ordered
 for (i = 0; i < 10; i++)
    {
#pragma omp ordered
 ;
    }
}

void
f6 (void)
{
#pragma omp critical (foo)
#pragma omp critical (bar)
 ;
#pragma omp critical
#pragma omp critical (baz)
 ;
}

void
f7 (void)
{
#pragma omp critical (foo2)
#pragma omp critical
 ;
#pragma omp critical (bar)
#pragma omp critical (bar)
 ;
#pragma omp critical
#pragma omp critical
 ;
}
