int global;
int foo1() {
  if (global > 0)
    return 0;
  else if (global < 0)
    return _Generic(global, double: 1, float: 2, default: 3);
  return 1;
}
int foo2() {
  if (global > 0)
    return 0;
  else if (global < 0)
    return _Generic(global, double: 1, int: 2, default: 4);
  return 1;
}
int foo3() {
  if (global > 0)
    return 0;
  else if (global < 0)
    return _Generic(global, double: 1, default: 4);
  return 1;
}
