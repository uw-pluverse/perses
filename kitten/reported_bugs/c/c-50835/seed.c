


typedef int veci __attribute__ ((vector_size (4 * sizeof (int))));

int c;

void f (veci *a)
{
  *a = *a + ++c;
}
