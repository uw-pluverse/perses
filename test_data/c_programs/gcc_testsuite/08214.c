



int a;
extern void (*p[2])(int n);
void abort (void);
int
main()
{ int i;


  for (i = 0;i<1000;i++)
    p[0](1);

  for (i = 0;i<1000;i++)
    p[i%2](2);
  if (a != 1000)
    abort ();

  return 0;
}
