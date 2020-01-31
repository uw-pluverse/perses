




volatile float f = __builtin_inf ();

int main ()
{
  __fp16 h = f;
  if (h != __builtin_inf ())
    __builtin_abort ();
  return 0;
}
