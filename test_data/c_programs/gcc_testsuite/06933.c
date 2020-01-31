





int f (void);
static inline void g(int t)
{
 int a;
 while (a < f())
  ;
}
void h(int t)
{
 g(t);
}
