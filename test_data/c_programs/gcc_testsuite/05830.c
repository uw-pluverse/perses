


typedef long vec __attribute__ ((vector_size (2 * sizeof(long))));

void f (vec *r)
{
  vec a = { -2, 666 };
  vec b = { 3, 2 };
  *r = a < b;
}
