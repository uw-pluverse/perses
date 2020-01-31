extern int i;



void
f_acc_parallel (void)
{
 {
 ;
 ;
 ;
 }
}



void
f_acc_kernels (void)
{
 {
 ;
 ;
 ;
 }
}

void
f_acc_data (void)
{
  unsigned int i;
 {
 for (i = 0; i < 2; ++i)
      ;

 {
 for (i = 0; i < 2; ++i)
 ;
    }
  }
}

void
f_acc_routine (void)
{
 ;
}

void
f (void)
{
  int i, v = 0;

 for (i = 0; i < 10; i++)
    v++;
}
