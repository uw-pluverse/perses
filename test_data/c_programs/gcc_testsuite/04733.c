

void foo()
{
  int l;

  bad1:
 goto bad1;
 goto bad1;
 goto bad1;
 for (l = 0; l < 2; ++l)
      goto bad1;

  goto bad2_parallel;
 {
      bad2_parallel: ;
    }

  goto bad2_kernels;
 {
      bad2_kernels: ;
    }

  goto bad2_data;
 {
      bad2_data: ;
    }

  goto bad2_loop;
 for (l = 0; l < 2; ++l)
    {
      bad2_loop: ;
    }

 {
      int i;
      goto ok1_parallel;
      for (i = 0; i < 10; ++i)
 { ok1_parallel: break; }
    }

 {
      int i;
      goto ok1_kernels;
      for (i = 0; i < 10; ++i)
 { ok1_kernels: break; }
    }

 {
      int i;
      goto ok1_data;
      for (i = 0; i < 10; ++i)
 { ok1_data: break; }
    }

 for (l = 0; l < 2; ++l)
      {
 int i;
 goto ok1_loop;
 for (i = 0; i < 10; ++i)
   { ok1_loop: break; }
      }
}
