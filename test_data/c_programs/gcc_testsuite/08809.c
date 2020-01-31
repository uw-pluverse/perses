



extern void abort(void);

float foo(float f)
{
  if (f < 0.0f)
    f = -f;

  return f;
}

int main(void)
{
  if (foo (-1.0f) != 1.0f)
    abort ();

  return 0;
}
