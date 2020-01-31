


typedef struct {
  char a:1;
  char b:7;
  int c;
} BitStruct;

volatile BitStruct bits;

int foo ()
{
  return bits.b;
}
