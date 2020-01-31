






extern volatile unsigned int frob;

volatile unsigned int frob = 0;

void foo (unsigned int val)
{
  frob = val;
}
