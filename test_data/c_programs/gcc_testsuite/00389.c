



extern unsigned long long set_mask[65];
extern unsigned long long xyzzy(int) __attribute__((pure));

int valid (int x)
{
  return(xyzzy(x) & set_mask[x]);
}
