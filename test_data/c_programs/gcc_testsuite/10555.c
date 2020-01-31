

static void *resolver ()
{
  return 0;
}

extern int magic (void)
     __attribute__ ((ifunc ("resolver")));
extern int magic (void)
     __attribute__ ((alias ("resolver")));

extern int spell (void)
{
  return 0;
}
extern int spell (void)
     __attribute__ ((ifunc ("resolver")));

extern int mantra (void)
     __attribute__ ((alias ("resolver")));
extern int mantra (void)
     __attribute__ ((ifunc ("resolver")));

extern int saying (void)
     __attribute__ ((weak,ifunc ("resolver")));
extern int maxim (void)
     __attribute__ ((ifunc ("resolver"),weak));
