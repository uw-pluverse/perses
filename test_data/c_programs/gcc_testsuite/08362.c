


struct a {
  int x, y, z;
};

struct b {
  struct a w, z;
};

int main (void)
{
  struct a az = { 0 };
  struct a anz = { 1 };
  struct a aez = { 0, 0 };

  struct b bz = { 0 };
  struct b bnz = { 0, 0, 0, 0, 0, 0 };

  return 0;
}
