
extern void abort (void);
int main ()
{
  if ('\234a' < 0)
    abort ();
  if ('!\234abc' != '\234abc')
    abort ();
  return 0;
}
