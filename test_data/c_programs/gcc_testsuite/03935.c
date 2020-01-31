


typedef __attribute__((vector_size(16) )) signed char qword;
typedef __attribute__((vector_size(16) )) unsigned int VU32;
extern short g[192 +16];
void f(qword);
void f1 (unsigned ctr)
{
  VU32 pin;
  pin = (VU32){(long unsigned int)&g[16]};
  do {
   f((qword)pin);
   ctr--;
  }
while(ctr);
}
