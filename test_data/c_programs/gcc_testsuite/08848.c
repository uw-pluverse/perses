




void __attribute__ ((noinline)) Foo (int *ary)
{
  int ix;

#pragma acc parallel num_workers(32) vector_length(32) copyout(ary[0:N])
 {

#pragma acc loop worker vector
 for (unsigned ix = 0; ix < (32*32*32+17); ix++)
      {
 ary[ix] = ix;
      }
  }
}

int main ()
{
  int ary[(32*32*32+17)];

  Foo (ary);

  return 0;
}
