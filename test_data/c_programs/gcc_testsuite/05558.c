


typedef char __attribute__ ((vector_size (4))) v4qi;

v4qi v;
void ret(char a)
{
  v4qi c={a,a,a,a},d={a,a,a,a};
  v = (c!=d);
}
