int expect_taken(int x) {
  if (__builtin_expect (x, 1))
    return 0;
  return x;
}
int expect_not_taken(int x) {
  if (__builtin_expect (x, 0))
    return 0;
  return x;
}
int x;
int y(void);
void foo();
void expect_value_side_effects() {
  if (__builtin_expect (x, y()))
    foo ();
}
void isigprocmask(void);
long bar();
int main() {
  (void) __builtin_expect((isigprocmask(), 0), bar());
}
int switch_cond(int x) {
  switch(__builtin_expect(x, 5)) {
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
