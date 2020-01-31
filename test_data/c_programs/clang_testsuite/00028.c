int SValBuilderLogicNoCrash(int *x) {
  return 3 - (int)(x +3);
}
void pr15863() {
  extern int getBool();
  _Bool a = getBool();
  (void)!a;
}
