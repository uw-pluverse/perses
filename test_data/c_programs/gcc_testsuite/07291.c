



extern unsigned long jb[];
extern int my_setjmp(unsigned long jb[]) __attribute__((returns_twice));
extern int decode(const char*);

static inline int wrapper(const char **s_ptr)
{
    if (my_setjmp(jb) == 0) {
 const char *s = *s_ptr;
 while (decode(s) != 0)
     *s_ptr = ++s;
 return 0;
    } else
 return -1;
}

void parse(const char *data)
{
    const char *s = data;
    if (!(wrapper(&s) == -1 && (s - data) == 1))
 __builtin_abort();
}
