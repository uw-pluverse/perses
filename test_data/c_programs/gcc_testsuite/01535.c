




extern void __crt0_start (void) __attribute__ ((noreturn));
extern void abort (void) __attribute__ ((noreturn));
extern void exit (int) __attribute__ ((noreturn));

int a;
int b = 0;
int c = 1;
int __attribute__((noinit)) d;
int __attribute__((persistent)) e = 2;

int
main (void)
{

  if (a != 0)
    abort ();






  if (e == 2)

  if (b != 0 || c != 1)
    abort ();

  switch (e)
    {
    case 2:

      a = b = c = d = e = 3;
      break;

    case 3:

      if (d != 3)
 abort ();
      exit (0);

    default:

      abort ();
    }


  __crt0_start ();


  abort ();
}
