


typedef struct {
  volatile unsigned long a:8;
  volatile unsigned long b:8;
  volatile unsigned long c:16;
} BitStruct;

BitStruct bits;

unsigned long foo ()
{
  return bits.b;
}
