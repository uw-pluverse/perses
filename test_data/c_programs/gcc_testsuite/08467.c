



int level = 1;

void abort (void);
char *strstr (const char *, const char *);
int strcmp (const char *, const char *);
int main ()
{

  if (level != 1)
    abort ();

  if (!strstr ("../gcc-seed-programs/gcc.dg/cpp/trad/builtins.c", "builtins.c"))
    abort ();

  if (!strcmp ("../gcc-seed-programs/gcc.dg/cpp/trad/builtins.c", "builtins.c"))
    abort ();

  return 0;
}
