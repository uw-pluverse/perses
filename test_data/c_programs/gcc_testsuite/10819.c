void * memcpy (void *, void *, long unsigned int);
void bar (void *p, void *q, unsigned s)
{
  memcpy (p, q, s);
}
