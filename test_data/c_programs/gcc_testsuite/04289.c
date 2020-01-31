


char flags;

int bug12292(int t)
{
 flags &= ~(1 << (t + 4));
}
