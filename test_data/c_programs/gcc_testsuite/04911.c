

int x;
volatile int y;
volatile unsigned char z;

void f1(void)
{
 x++;
 x--;
 ++x;
 --x;
 x += 1;
 x -= y;
 x |= 1;
 x &= 1;
 x ^= 1;
 x *= 3;
 x /= 3;
 x /= 3;
 x <<= 3;
 x >>= 3;
}

void f2(void)
{
 y++;
 y--;
 ++y;
 --y;
 y += 1;
 y -= x;
 y |= 1;
 y &= 1;
 y ^= 1;
 y *= 3;
 y /= 3;
 y /= 3;
 y <<= 3;
 y >>= 3;
}

void f3(void)
{
 z++;
 z--;
 ++z;
 --z;
 z += 1;
 z |= 1;
 z &= 1;
 z ^= 1;
 z *= 3;
 z /= 3;
 z /= 3;
 z <<= 3;
 z >>= 3;
}
