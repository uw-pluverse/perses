void *g(unsigned long len);
void
f(int n)
{
 unsigned begin_set[n];
 g(sizeof(begin_set));
}
