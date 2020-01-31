extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
char *
strchr (const char *s, int c)
{





  for (;;)
    {
      if (*s == c)
 return (char *) s;
      if (*s == 0)
 return 0;
      s++;
    }
}

__attribute__ ((__noinline__))
char *
index (const char *s, int c)
{
  return strchr (s, c);
}

