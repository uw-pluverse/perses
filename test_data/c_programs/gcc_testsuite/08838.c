

struct s
{
  int i1 : sizeof (int) * 8;
  int i2 : sizeof (int) * 8;
  int i3 : sizeof (int) * 8;
  int i4 : sizeof (int) * 8;
};

int f[sizeof (struct s) != sizeof (int) * 4 ? -1 : 1];
