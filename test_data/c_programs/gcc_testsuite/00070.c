



struct S
{
  float *buf;
  int size;
};

void
foo (struct S *s)
{
  int i;
  for (i = 0; i < s->size; ++i)
    s->buf[i] = 0;
}
