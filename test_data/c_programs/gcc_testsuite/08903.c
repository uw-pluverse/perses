






extern void abort (void);



extern int blah;

static const struct {
    int *y;
    const char x[32] __attribute__((aligned(32)));
} xconstant = { &blah, "01234567899876543210123456789000" };

typedef int v4si __attribute__((vector_size(16)));

int main()
{
  if (sizeof (int) != 4)
    return 0;
  if (1234 == 4321)
    {
      if (*(int *)&xconstant.x[4] != 0x34353637)
 abort ();
      if ((*(v4si *)&xconstant.x[16])[1] != 0x31323334)
 abort ();
      if (__imag (*(_Complex int *)&xconstant.x[8]) != 0x37363534)
 abort ();
    }
  else if (1234 == 1234)
    {
      if (*(int *)&xconstant.x[4] != 0x37363534)
 abort ();
      if ((*(v4si *)&xconstant.x[16])[1] != 0x34333231)
 abort ();
      if (__imag (*(_Complex int *)&xconstant.x[8]) != 0x34353637)
 abort ();
    }
  return 0;
}
