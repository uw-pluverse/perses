extern int i;

void
f_acc_parallel (void)
{
 {
 for (i = 0; i < 2; ++i)
      ;
  }
}


void
f_acc_kernels (void)
{
 {
 for (i = 0; i < 2; ++i)
      ;
  }
}


void
f_acc_data (void)
{
 {
 ;

 {
 for (i = 0; i < 2; ++i)
 ;
    }

 ;

 {
 for (i = 0; i < 2; ++i)
 ;
    }

 ;




 {
 ;

 {
 for (i = 0; i < 2; ++i)
   ;
      }

 ;

 {
 for (i = 0; i < 2; ++i)
   ;
      }

 ;



 }
  }
}
