static inline int sabrina (void) __attribute__((always_inline));
static inline int sabrina (void)
{
  return 13;
}
int bar (void)
{
  return sabrina () + 68;
}
