




typedef long unsigned int uintptr_t;




typedef __attribute__ ((__vector_size__ (16))) signed char qword;
typedef __attribute__ ((__vector_size__ (16))) uintptr_t VU;

extern short g[192 + 16];

void f (qword);

void f1 (unsigned ctr)
{
  VU pin;

  pin = (VU){(uintptr_t) &g[16]};
  do
    {
      f ((qword) pin);
      ctr--;
    }
  while (ctr);
}
