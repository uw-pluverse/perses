






typedef float vecf __attribute__ ((vector_size (16)));
extern vecf j, k;

void fun (void)
{
  j = k;
}
