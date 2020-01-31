

extern int foo(void);
extern void bar(void);

int main ()
{

#pragma omp parallel if (foo () > 10) if (foo () == 3)
 {
      bar ();
    }

#pragma omp parallel num_threads (3) num_threads (20)
 {
      bar ();
    }


#pragma omp parallel if (foo () == 10) num_threads (foo ())
 {
      bar ();
    }
}
