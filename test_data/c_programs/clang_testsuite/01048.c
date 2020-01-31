int testBoolAssign(void) {
  int ss;
  if ((ss = ss && ss)) {}
  return 1;
}
