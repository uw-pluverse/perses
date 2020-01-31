


extern void abort (void);
extern void exit (int);


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;



typedef long long int INT64;

inline void
debug(int i1, int i2, int i3, int i4, int i5,
      int i6, int i7, int i8, int i9, ...)
{
  va_list ap;

  __builtin_va_start(ap, i9);

  if (__builtin_va_arg(ap, int) != 10)
    abort ();
  if (__builtin_va_arg(ap, INT64) != 0x123400005678LL)
    abort ();

  __builtin_va_end(ap);
}

int
main(void)
{
  debug(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0x123400005678LL);
  exit(0);
}
