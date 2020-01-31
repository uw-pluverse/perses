


static int *foo = (int *) (unsigned long) 0x7800000;

int func(void) __attribute__ ((noinline));

extern int bar(void);

int func(void)
{
   if (*foo) {
      return 1;
   }
   return 0;

}

int foobar(void)
{

   if (func()) {
      *foo = 1;
   }
   return func();
}
