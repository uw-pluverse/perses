


extern void abort (void) __attribute__ ((__nothrow__)) __attribute__
((__noreturn__));
extern void exit (int __status) __attribute__ ((__nothrow__))
__attribute__ ((__noreturn__));
int useboot (void *);

struct bootLoader {
  int x;
};

void
zap(struct bootLoader *bootLoader)
{




  int *boot = &bootLoader->x;

  if (bootLoader)
    {
      useboot (boot);
    }
}

int
useboot (void *boot)
{
  abort ();
}

int
main()
{
  zap (0);
  return 0;
}
