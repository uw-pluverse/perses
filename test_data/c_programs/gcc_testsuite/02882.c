







typedef long int __jmp_buf[8];
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;



struct __jmp_buf_tag
  {




    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };




typedef struct __jmp_buf_tag jmp_buf[1];



extern int setjmp (jmp_buf __env) __attribute__ ((__nothrow__));






extern int __sigsetjmp (struct __jmp_buf_tag __env[1], int __savemask) __attribute__ ((__nothrow__));



extern int _setjmp (struct __jmp_buf_tag __env[1]) __attribute__ ((__nothrow__));
extern void longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));

extern void abort (void);
extern void exit (int);

static jmp_buf env;

void baz (void)
{
  __asm__ volatile ("" : : : "memory");
}

static inline int g(int x)
{
    if (x)
    {
        baz();
        return 0;
    }
    else
    {
        baz();
        return 1;
    }
}

int f(int *e)
{
    if (*e)
      return 1;

    int x = _setjmp (env);
    int n = g(x);
    if (n == 0)
      exit(0);
    if (x)
      abort();
    longjmp(env, 42);
}

int main(int argc, char** argv)
{
    int v = 0;
    return f(&v);
}
