

struct s
{
  int i1 : sizeof (int) * 8;
  int i2 : sizeof (int) * 8;
  int i3 : sizeof (int) * 8;
  int i4 : sizeof (int) * 8;
  int i5 : sizeof (int) * 8;
  int i6 : sizeof (int) * 8;
  int i7 : sizeof (int) * 8;
  int i8 : sizeof (int) * 8;
};

int f[sizeof (struct s) != sizeof (int) * 8 ? -1 : 1];
