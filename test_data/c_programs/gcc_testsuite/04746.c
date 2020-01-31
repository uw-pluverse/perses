int
kernels_empty (void)
{
 ;

  return 0;
}

int
kernels_eternal (void)
{
 {
    while (1)
      ;
  }

  return 0;
}

int
kernels_noreturn (void)
{
 __builtin_abort ();

  return 0;
}


float b[10][15][10];

void
kernels_loop_ptr_it (void)
{
  float *i;

 {
 for (i = &b[0][0][0]; i < &b[0][0][10]; i++)
      ;
  }
}
