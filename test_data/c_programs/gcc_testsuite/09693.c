


int
bar ()
{
  int a = 0, i;

#pragma omp parallel for num_threads (3) reduction (+:a) schedule(static, 1)
 for (i = 0; i < 10; i++)
    a += i;

  return a;
}
