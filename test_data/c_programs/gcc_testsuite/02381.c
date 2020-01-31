

extern void abort (void);
extern void exit (int);

struct A {
  unsigned short a : 5;
  unsigned short b : 5;
  unsigned short c : 6;
};

struct B {
  unsigned short a : 5;
  unsigned short b : 3;
  unsigned short c : 8;
};

int main ()
{

  if ((unsigned short) 65521 != 65521)
    exit (0);

  if (sizeof (struct A) != sizeof (struct B))
    abort ();

  exit (0);
}
