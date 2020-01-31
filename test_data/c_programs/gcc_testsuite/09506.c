







extern void sysbar (unsigned char *);

unsigned char *
sysfn1 (void *p)
{
   unsigned char *uc = (void *) 1;
   uc = (void *) 1;
   sysbar ((void *) 1);
   return (void *) 1;
}

extern void sysbar2 (int);

int
sysfn2 (void)
{
  int a = (void *) 0;
  a = (void *) 0;
  sysbar2 ((void *) 0);
  return (void *) 0;
}

int
sysfn3 (void)
{
  return (void *) 0;
}

extern void bar (unsigned char *);

unsigned char *
f (void *p)
{
   unsigned char *uc = (void *) 1;
   uc = (void *) 1;
   bar ((void *) 1);
   return (void *) 1;
}
