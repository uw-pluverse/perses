


typedef unsigned vec __attribute__ ((vector_size (4*sizeof(int))));
void
f (vec *a)
{
  vec s = { 5, 5, 5, 5 };
  *a = *a << s;
}
