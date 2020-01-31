










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

jmp_buf *alloc_jmp_buf ();
int foo (void *);

int
test (int op, int noside)
{
  void *argvec = 0;

  if (op)
    {
      jmp_buf *buf = alloc_jmp_buf ();
      _setjmp (*buf);

      if (noside)
        goto nosideret;

    do_call_it:

      if (noside)
        goto nosideret;

      return foo (argvec);
    }

  argvec = __builtin_alloca (1);
  goto do_call_it;

nosideret:
  return 1;
}
