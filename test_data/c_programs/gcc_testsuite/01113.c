




extern void __attribute__ ((sysv_abi)) abort (void);
typedef int (*func)(void *, char *, char *, short, long long);
extern func get_callback (void);

int __attribute__ ((sysv_abi))
main ()
{
  func callme = get_callback ();
  if (callme (0, 0, 0, 0x1234, 0x1234567890abcdefLL))
    abort ();
  return 0;
}
