


typedef struct
{
  unsigned char c1;
  unsigned char c2;
  unsigned char c3;
  unsigned char c4;
} foo_t;

int



foo (foo_t x)
{
   return x.c2 != 0;
}
