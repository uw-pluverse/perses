




extern void __attribute__ ((sysv_abi)) abort (void);
extern int fct2 (int, ...);



int __attribute__ ((sysv_abi))
main()
{
  if (fct2 (-1, 1ll,2ll,3ll,4ll,5ll,6ll,7ll,0ll) != 0)
    abort ();
  return 0;
}
