



extern void abort (void);

#pragma pack(1)
volatile struct S0 {
   signed a : 7;
   unsigned b : 28;

} g = {0,0xfffffff};

int main() {
  unsigned b = g.b;
  if (b != 0xfffffff)
    abort ();
  return 0;
}
