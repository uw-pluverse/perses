int value(void);
int main()
{
    int a = value();
    if (a == 0x1234567812345678L)
        return 0;
    if (a != 0x1234567812345678L)
        return 0;
    if (a < 0x1234567812345678L)
        return 0;
    if (a <= 0x1234567812345678L)
        return 0;
    if (a > 0x1234567812345678L)
        return 0;
    if (a >= 0x1234567812345678L)
        return 0;
    if (0x1234567812345678L == a)
        return 0;
    if (0x1234567812345678L != a)
        return 0;
    if (0x1234567812345678L < a)
        return 0;
    if (0x1234567812345678L <= a)
        return 0;
    if (0x1234567812345678L > a)
        return 0;
    if (0x1234567812345678L >= a)
        return 0;
    if (a == 0x1234567812345678LL)
      return 0;
    if (a == -0x1234567812345678L)
      return 0;
    if (a < -0x1234567812345678L)
      return 0;
    if (a > -0x1234567812345678L)
      return 0;
    if (a <= -0x1234567812345678L)
      return 0;
    if (a >= -0x1234567812345678L)
      return 0;
    if (a == 0x12345678L)
      return 1;
    short s = value();
    if (s == 0x1234567812345678L)
        return 0;
    if (s != 0x1234567812345678L)
        return 0;
    if (s < 0x1234567812345678L)
        return 0;
    if (s <= 0x1234567812345678L)
        return 0;
    if (s > 0x1234567812345678L)
        return 0;
    if (s >= 0x1234567812345678L)
        return 0;
    if (0x1234567812345678L == s)
        return 0;
    if (0x1234567812345678L != s)
        return 0;
    if (0x1234567812345678L < s)
        return 0;
    if (0x1234567812345678L <= s)
        return 0;
    if (0x1234567812345678L > s)
        return 0;
    if (0x1234567812345678L >= s)
        return 0;
    long l = value();
    if (l == 0x1234567812345678L)
        return 0;
    if (l != 0x1234567812345678L)
        return 0;
    if (l < 0x1234567812345678L)
        return 0;
    if (l <= 0x1234567812345678L)
        return 0;
    if (l > 0x1234567812345678L)
        return 0;
    if (l >= 0x1234567812345678L)
        return 0;
    if (0x1234567812345678L == l)
        return 0;
    if (0x1234567812345678L != l)
        return 0;
    if (0x1234567812345678L < l)
        return 0;
    if (0x1234567812345678L <= l)
        return 0;
    if (0x1234567812345678L > l)
        return 0;
    if (0x1234567812345678L >= l)
        return 0;
    unsigned un = 0;
    if (un == 0x0000000000000000L)
        return 0;
    if (un != 0x0000000000000000L)
        return 0;
    if (un < 0x0000000000000000L)
        return 0;
    if (un <= 0x0000000000000000L)
        return 0;
    if (un > 0x0000000000000000L)
        return 0;
    if (un >= 0x0000000000000000L)
        return 0;
    if (0x0000000000000000L == un)
        return 0;
    if (0x0000000000000000L != un)
        return 0;
    if (0x0000000000000000L < un)
        return 0;
    if (0x0000000000000000L <= un)
        return 0;
    if (0x0000000000000000L > un)
        return 0;
    if (0x0000000000000000L >= un)
        return 0;
    float fl = 0;
    if (fl == 0x0000000000000000L)
      return 0;
    float dl = 0;
    if (dl == 0x0000000000000000L)
      return 0;
    enum E {
    yes,
    no,
    maybe
    };
    enum E e;
    if (e == 0x1234567812345678L)
      return 0;
    return 1;
}
