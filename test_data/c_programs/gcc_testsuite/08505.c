





int
asr1 (int a, int b)
{
  return ~((~a) >> b);
}

long
asr1l (long a, long b)
{
  return ~((~a) >> b);
}

int
asr_conv (unsigned a, unsigned b)
{
  return ~((int)~a >> b);
}

unsigned
asr_conv2 (unsigned a, unsigned b)
{
  return ~(unsigned)((int)~a >> b);
}

unsigned
asr_conv3 (int a, int b)
{
  return ~(unsigned)(~a >> b);
}

typedef int int32_t;
typedef long int int64_t;

int32_t
asr_conv4 (int64_t a, int b)
{
  return ~((int32_t)~a >> b);
}

int32_t
asr_conv5 (int64_t a, int b)
{
  return ~(int32_t)(~a >> b);
}

int
asr2 (int a, int b)
{
  return -((-a - 1) >> b) - 1;
}

int
asr3 (int a, int b)
{
  return a < 0 ? ~((~a) >> b) : a >> b;
}

int64_t
asr3l (int64_t a, int b)
{
  return a < 0 ? ~((~a) >> b) : a >> b;
}

int
asr4 (int a, int b)
{
  return a < 0 ? -((-a - 1) >> b) - 1 : a >> b;
}
