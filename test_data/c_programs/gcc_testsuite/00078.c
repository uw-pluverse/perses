


typedef unsigned int uword_t __attribute__ ((mode (__word__)));

extern int error;

__attribute__((interrupt))
void
fn1 (void *p, short error_code)
{
}

__attribute__((interrupt))
void
fn2 (void)
{
}

__attribute__((interrupt))
void
fn3 (uword_t error_code)
{
  error = error_code;
}

__attribute__((interrupt))
void
fn4 (uword_t error_code, void *frame)
{
  error = error_code;
}

extern int fn5 (void *) __attribute__ ((interrupt));

int
fn5 (void *frame)
{
  return 0;
}
