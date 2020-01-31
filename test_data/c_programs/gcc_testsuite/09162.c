

extern void *memcpy(void *dest, const void *src, long unsigned int n);

void bar (void *, void *, void *);

void foo
  (void *p, char *data, unsigned data_len)
{
  int buffer[8];
  int buf2[8];
  unsigned i;
  for (i = 0; i + 8 <= data_len; i += 8)
    bar (p, buffer, data + i);
  memcpy (buf2, data + i, data_len);
}
