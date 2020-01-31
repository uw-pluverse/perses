

static int i;
extern int j;
extern inline int func1 (void) {
  return i++;
}
extern inline int func2 (void) {
  return j++;
}
inline int func3 (void)
{
  return i++;
}
