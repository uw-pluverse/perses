


extern int check_int (int *i, void *, int align);
typedef int aligned __attribute__((aligned(64)));
typedef unsigned int uword_t __attribute__ ((mode (__word__)));

__attribute__((interrupt))
void
foo (void *frame, uword_t error_code)
{
  aligned j;
  if (check_int (frame, &j, __alignof__(j)))
    __builtin_abort ();
}
