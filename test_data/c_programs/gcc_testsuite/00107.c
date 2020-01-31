
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));
void f(void*p,...){}
void g(void*p,long a,long b){((a==8) ? (void) (0) : __assert_fail ("a==8", "../gcc-seed-programs/gcc.target/i386/pr64291-2.c", 4, __PRETTY_FUNCTION__));}
typedef struct
{
  int _mp_size;
  unsigned long *_mp_d;
} __mpz_struct;
typedef __mpz_struct mpz_t[1];
void h(mpz_t x) {
  x->_mp_d=0;
  x->_mp_size=0;
}
