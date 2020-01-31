


typedef int v4i __attribute__((vector_size(4*sizeof(int))));



void use (v4i const *z);

void
f (v4i *x, v4i *y)
{
  v4i const zz = *x < *y;
  use (&zz);
}



void
g (v4i *x, v4i const *y, v4i *z, v4i *t)
{
  *z = *x < *y | *x == *y;
  *t = *x < *y & *x > *y;
}
