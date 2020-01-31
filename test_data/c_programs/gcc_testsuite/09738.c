




extern void bar (void);
extern char q[];
int t;
#pragma omp threadprivate (t)

void
foo (int x)
{
  char *pp;
  struct S { int i; int j; } s;
  char a[32];
  double d;
  int i;
  const int c = 8;
#pragma omp p shared (x, x)
 ;
#pragma omp p private (x) private (x)
 ;
#pragma omp p shared (x) firstprivate (x)
 ;
#pragma omp p firstprivate (x, x)
 ;
#pragma omp p for shared (x) lastprivate (x)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p for private (x) lastprivate (x)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p for lastprivate (x, x)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p for linear (x, x)
 for (i = 0; i < 10; i++)
    ;
#pragma omp single private (x) copyprivate (x)
 ;
#pragma omp p shared (bar)
 ;
#pragma omp p private (bar)
 ;
#pragma omp p firstprivate (bar)
 ;
#pragma omp p reduction (+:pp)
 ;
#pragma omp p reduction (*:s)
 ;
#pragma omp p reduction (-:a)
 ;
  d = 0;
#pragma omp p reduction (*:d)
 ;
#pragma omp p reduction (|:d)
 ;
#pragma omp p reduction (&&:d)
 ;
#pragma omp p copyin (d)
 ;
#pragma omp p copyin (x)
 ;
#pragma omp p for firstprivate (x) lastprivate (x)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p private (q)
 ;
#pragma omp p firstprivate (q)
 ;
#pragma omp p for lastprivate (q)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p shared (t)
 ;
#pragma omp p private (t)
 ;
#pragma omp p firstprivate (t)
 ;
#pragma omp p for lastprivate (t)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p reduction (*:t)
 ;
#pragma omp p for linear (t)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p shared (c)
 ;
#pragma omp p private (c)
 ;
#pragma omp p firstprivate (c)
 ;
#pragma omp p for lastprivate (c)
 for (i = 0; i < 10; i++)
    ;
#pragma omp p reduction (*:c)
 ;
#pragma omp p for linear (c)
 for (i = 0; i < 10; i++)
    ;
}
