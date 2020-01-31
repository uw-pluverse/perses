int freebsd_kernel_printf(const char *, ...) __attribute__((__format__(__freebsd_kprintf__, 1, 2)));
void check_freebsd_kernel_extensions(int i, long l, char *s, short h)
{
  freebsd_kernel_printf("reg=%b\n", i, "\10\2BITTWO\1BITONE\n");
  freebsd_kernel_printf("reg=%b\n", l, "\10\2BITTWO\1BITONE\n");
  freebsd_kernel_printf("reg=%b\n", i, l);
  freebsd_kernel_printf("reg=%b\n", i);
  freebsd_kernel_printf("reg=%b\n", i, "\10\2BITTWO\1BITONE\n", l);
  freebsd_kernel_printf("%6D", s, ":");
  freebsd_kernel_printf("%6D", i, ":");
  freebsd_kernel_printf("%6D", s, i);
  freebsd_kernel_printf("%6D", s);
  freebsd_kernel_printf("%6D", s, ":", i);
  freebsd_kernel_printf("%*D", 42, s, ":");
  freebsd_kernel_printf("%*D", 42, i, ":");
  freebsd_kernel_printf("%*D", 42, s, i);
  freebsd_kernel_printf("%*D", 42, s);
  freebsd_kernel_printf("%*D", 42, s, ":", i);
  freebsd_kernel_printf("%r", i);
  freebsd_kernel_printf("%r", l);
  freebsd_kernel_printf("%lr", i);
  freebsd_kernel_printf("%lr", l);
  freebsd_kernel_printf("%hr", i);
  freebsd_kernel_printf("%hr", h);
  freebsd_kernel_printf("%hy", i);
  freebsd_kernel_printf("%hy", h);
  freebsd_kernel_printf("%y", i);
  freebsd_kernel_printf("%y", l);
  freebsd_kernel_printf("%ly", i);
  freebsd_kernel_printf("%ly", l);
}
