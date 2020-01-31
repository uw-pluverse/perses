



typedef int v8si __attribute__ ((vector_size (32)));

v8si
foo (v8si v)
{
  return v %= -v;
}
