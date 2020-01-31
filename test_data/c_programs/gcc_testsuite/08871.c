




extern void abort (void);

struct s {
    int i;
    char c[];
} s = { 1, "01234" };

long unsigned int f (void) { return __builtin_object_size (&s.c, 0); }

int
main()
{
  if (f() != sizeof ("01234"))
    abort ();

  return 0;
}
