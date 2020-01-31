enum locality { none, low, moderate, high };
enum rw { read, write };

int arr[10];

void
good_const (const int *p)
{
  __builtin_prefetch (p, 0, 0);
  __builtin_prefetch (p, 0, 1);
  __builtin_prefetch (p, 0, 2);
  __builtin_prefetch (p, 0, 3);
  __builtin_prefetch (p, 1, 0);
  __builtin_prefetch (p, 1, 1);
  __builtin_prefetch (p, 1, 1);
  __builtin_prefetch (p, 1, 3);
}

void
good_enum (const int *p)
{
    __builtin_prefetch (p, read, none);
    __builtin_prefetch (p, read, low);
    __builtin_prefetch (p, read, moderate);
    __builtin_prefetch (p, read, high);
    __builtin_prefetch (p, write, none);
    __builtin_prefetch (p, write, low);
    __builtin_prefetch (p, write, moderate);
    __builtin_prefetch (p, write, high);
}

void
good_expr (const int *p)
{
  __builtin_prefetch (p, 1 - 1, 6 - (2 * 3));
  __builtin_prefetch (p, 1 + 0, 1 + 2);
}

void
good_vararg (const int *p)
{
  __builtin_prefetch (p, 0, 3);
  __builtin_prefetch (p, 0);
  __builtin_prefetch (p, 1);
  __builtin_prefetch (p);
}

int
main ()
{
  good_const (arr);
  good_enum (arr);
  good_expr (arr);
  good_vararg (arr);
  exit (0);
}
