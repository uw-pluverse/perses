

int do_something_evil (void);
inline __attribute__ ((always_inline)) void
q2(void)
{
  if (do_something_evil ())
    return;
  q2();
  q2();
}
