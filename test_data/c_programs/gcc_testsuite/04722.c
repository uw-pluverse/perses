


typedef long unsigned int size_t;
extern void *acc_copyin (void *, size_t);

void
foo (void)
{
  int a = 0;
  int *p = (int *)acc_copyin (&a, sizeof (a));

 {
    a = 0;
    *p = 1;
  }
}
