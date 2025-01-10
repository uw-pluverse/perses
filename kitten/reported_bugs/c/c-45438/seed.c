






extern void abort ();

__attribute__((vector_size(256))) int vec[2] = {{0}, {0}};

int
main()
{
  long vcc = 0;



  asm volatile ("s_mov_b32 vcc_lo, 0x12345689\n\t"
  "s_mov_b32 vcc_hi, 0xabcdef0"
  ::: "memory");




  asm volatile ("; no-op" : "=cV"(vcc) : "v"(vec[0]), "v"(vec[1]));


  if (vcc != 0xabcdef012345689)
    abort ();

  return 0;
}
