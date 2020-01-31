




typedef int __v8si __attribute__ ((__vector_size__ (32)));

extern __v8si x;

__v8si
foo (void)
{
  return x;
}
