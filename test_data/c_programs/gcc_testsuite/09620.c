

extern void bar (void);

int main (void)
{
  int i;
#pragma omp parallel for nowait
 for (i = 0; i < 10; i++)
    bar ();
}
