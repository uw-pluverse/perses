



extern void *alloca (long unsigned int);

void big (void);
inline void *q (void)
{
 return alloca (10);
}
inline void *t (void)
{
 return q ();
}
