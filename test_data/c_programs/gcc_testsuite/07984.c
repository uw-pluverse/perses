









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

struct x;

typedef struct x **(*a)(struct x *);
void d (const char *);

struct x {
    union {
 struct {
     union {
  a *i;
     } l;
     int s;
 } y;
    } e;
};

jmp_buf c;

void
b(struct x *r)
{
  int f;
  static int w = 0;
  volatile jmp_buf m;
  f = (*(((struct x *)r)->e.y.l.i[2]((struct x *)r)))->e.y.s;
  if (w++ != 0)
    __builtin_memcpy((char *)m, (const char *)c, sizeof(jmp_buf));
  if (_setjmp (c) == 0) {
      int z;
      for (z = 0; z < 0; ++z)
 ;
  }
  d((const char *)m);
}
