
extern int printk(const char *fmt, ...);

void foo (int x, int y)
{
  __label__ here;
  here:
  printk ("", &&here);
}
