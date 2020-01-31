

extern long unsigned int strlen (const char *) __attribute__ ((__pure__));
extern void link_error (void);

void
foo (const char *str)
{
  long unsigned int a = strlen (str);
  long unsigned int b = strlen (str);
  if (a != b)
    link_error ();
}
