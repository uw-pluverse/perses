int i1 = 1 << (sizeof (int) * 8 - 1);
int i2 = 9 << (sizeof (int) * 8 - 1);
int i3 = 10 << (sizeof (int) * 8 - 2);
int i4 = 2147483647 << 2;
int i5 = 2147483647 << (sizeof (int) * 8 - 1);
int i6 = -1 << (sizeof (int) * 8 - 1);
int i7 = -9 << (sizeof (int) * 8 - 1);
int i8 = -10 << (sizeof (int) * 8 - 2);
int i9 = -2147483647 << 2;
int i10 = -2147483647 << (sizeof (int) * 8 - 1);
int i11 = (-2147483647 -1) << 1;

int r1 = 1 >> (sizeof (int) * 8 - 1);
int r2 = 9 >> (sizeof (int) * 8 - 1);
int r3 = 10 >> (sizeof (int) * 8 - 2);
int r4 = 2147483647 >> 2;
int r5 = 2147483647 >> (sizeof (int) * 8 - 1);
int r6 = -1 >> (sizeof (int) * 8 - 1);
int r7 = -9 >> (sizeof (int) * 8 - 1);
int r8 = -10 >> (sizeof (int) * 8 - 2);
int r9 = -2147483647 >> 2;
int r10 = -2147483647 >> (sizeof (int) * 8 - 1);

unsigned u1 = 1 << (sizeof (int) * 8 - 1);
unsigned u2 = 9 << (sizeof (int) * 8 - 1);
unsigned u3 = 2U << (sizeof (int) * 8 - 1);
unsigned u4 = 9U << (sizeof (int) * 8 - 1);
unsigned u5 = 10U << (sizeof (int) * 8 - 2);

long long int l1 = 1LL << (sizeof (long long) * 8 - 1);
long long int l2 = 9LL << (sizeof (long long) * 8 - 1);
long long int l3 = 10LL << (sizeof (long long) * 8 - 2);
long long int l4 = 9223372036854775807LL << 2;
long long int l5 = 9223372036854775807LL << (sizeof (long long) * 8 - 1);
long long int l6 = -1LL << (sizeof (long long) * 8 - 1);
long long int l7 = -9LL << (sizeof (long long) * 8 - 1);
long long int l8 = -10LL << (sizeof (long long) * 8 - 2);
long long int l9 = -9223372036854775807LL << 2;
long long int l10 = -9223372036854775807LL << (sizeof (long long) * 8 - 1);
long long int l11 = (-9223372036854775807LL -1) << 1;

void
fn (void)
{
  const int a = 10;
  const long unsigned int b = (sizeof (int) * 8 - 1);
  int k1 = a << b;
  int k2 = 10 << b;
  int k3 = a << (sizeof (int) * 8 - 1);
}
