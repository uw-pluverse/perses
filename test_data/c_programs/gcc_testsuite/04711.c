


typedef long unsigned int size_t;
extern void *acc_copyin (void *, size_t);

void
foo (int *a, size_t n)
{
  int *p = (int *)acc_copyin (a, n);

 {
    a = 0;
    *p = 1;
  }
}
