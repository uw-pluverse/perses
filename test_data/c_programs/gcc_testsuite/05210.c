


extern void abort (void);
struct S { int i; };
struct S arr[32];
volatile int count = 0;

struct S __attribute__((noinline))
incr ()
{
  ++count;
}

int main()
{
  arr[count++] = incr ();
  if (count != 2)
    abort ();
  return 0;
}
