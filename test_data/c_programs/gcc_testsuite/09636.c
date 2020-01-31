

void
foo (int x)
{
  bad1:
#pragma omp target
 goto bad1;

  goto bad2;
#pragma omp target
 {
      bad2: ;
    }

#pragma omp target
 {
      int i;
      goto ok1;
      for (i = 0; i < 10; ++i)
 { ok1: break; }
    }

  switch (x)
  {
#pragma omp target
 { case 0:; }
  }
}
