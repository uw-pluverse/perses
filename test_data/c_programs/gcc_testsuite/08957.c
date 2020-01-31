





extern void do_something (void);
extern void do_something_else (void);

static int
init_foobar(void)
{
  do_something();
  do_something_else();
  return 0;
}

int init_module(void) __attribute__((alias("init_foobar")));
