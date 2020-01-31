

void
foo (int x)
{
  bad1:
#pragma omp taskgroup
 goto bad1;

  goto bad2;
#pragma omp taskgroup
 {
      bad2: ;
    }

#pragma omp taskgroup
 {
      int i;
      goto ok1;
      for (i = 0; i < 10; ++i)
 { ok1: break; }
    }

  switch (x)
  {
#pragma omp taskgroup
 { case 0:; }
  }
}
