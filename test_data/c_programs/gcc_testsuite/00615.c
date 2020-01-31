


extern void abort (void);

typedef float float16x4_t __attribute__ ((vector_size ((16))));

float a;
float b;

float16x4_t
make_vector ()
{
  return (float16x4_t) { 0, 0, a, b };
}

int
main (int argc, char **argv)
{
  a = 4.0;
  b = 3.0;
  float16x4_t vec = make_vector ();
  if (vec[0] != 0 || vec[1] != 0 || vec[2] != a || vec[3] != b)
    abort ();
  return 0;
}
