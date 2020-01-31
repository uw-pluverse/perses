


typedef long unsigned int size_t;
extern void *acc_copyin (void *, size_t);



void
foo (void)
{
  int a[2];
  int *p = (int *)acc_copyin (&a[0], sizeof (a));

 {
    a[0] = 0;
    *p = 1;
  }
}
