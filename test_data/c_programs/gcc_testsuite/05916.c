extern void abort (void);
extern void exit (int);

struct x
{
  unsigned b:1;
  unsigned c:1;
};

struct x i = { 1, 1 };

int
main ()
{
  i.b = 1;
  if (i.b == 1 && i.c == 0)
    exit (0);
  i.c = 0;
  if (i.b == 1 && i.c == 0)
    exit (0);
  abort ();
}
