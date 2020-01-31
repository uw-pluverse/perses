




typedef int __v4si __attribute__ ((__vector_size__ (16)));

extern __v4si x;

__v4si
foo (void)
{
  return x;
}
