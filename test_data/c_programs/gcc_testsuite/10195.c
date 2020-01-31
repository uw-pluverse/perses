


typedef double v2df __attribute__ ((vector_size (2 * sizeof (double))));

void do_div (v2df *a, v2df *b)
{
  *a = *b / (v2df) { 2.0, 2.0 };
}
