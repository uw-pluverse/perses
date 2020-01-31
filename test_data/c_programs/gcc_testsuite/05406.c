



struct thread_param
{
  long* buf;
  long iterations;
  long accesses;
} param;

void access_buf(struct thread_param* p)
{
  long i,j;
  long iterations = p->iterations;
  long accesses = p->accesses;
  for (i=0; i<iterations; i++)
    {
      long* pbuf = p->buf;
      for (j=0; j<accesses; j++)
 pbuf[j] += 1;
    }
}
