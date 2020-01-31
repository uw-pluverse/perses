


typedef int v4si __attribute__((vector_size(16)));

int f(v4si t)
{
  union {
      v4si t1;
      int t2[4];
  } u;
  u.t1 = t;
  return u.t2[1];
}
