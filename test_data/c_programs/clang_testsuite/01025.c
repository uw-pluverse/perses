void foo();
void branch(int x) {
  if (__builtin_unpredictable(x > 0))
    foo ();
}
int unpredictable_switch(int x) {
  switch(__builtin_unpredictable(x)) {
  default:
    return 0;
  case 0:
  case 1:
  case 2:
    return 1;
  case 5:
    return 5;
  };
  return 0;
}
