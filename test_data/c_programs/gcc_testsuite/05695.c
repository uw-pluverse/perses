



typedef unsigned int u_int32_t;
typedef unsigned char u_int8_t;



typedef volatile struct AT91RM9200_regs {
  u_int32_t SVR[32];
} AT91RM9200_regs_t;



extern const u_int32_t __IntTable[32];

int main()
{
  int c;

  for (c = 0; c < 32; c++)
    ((AT91RM9200_regs_t*)0xFFF00000)->SVR[c] = __IntTable[c];

  return 0;
}
