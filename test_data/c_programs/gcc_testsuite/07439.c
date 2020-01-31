


typedef unsigned char v4qi __attribute__ ((vector_size (4)));

v4qi c;

void foo()
{
  v4qi a = { 1, 2, 3, 4 };
  v4qi b = { 5, 6, 7, 8 };
  c = a + b;
}
