void if_assign(void) {
  int i;
  if (i = 4) {}
  if ((i = 4)) {}
}
void bitwise_rel(unsigned i) {
  (void)(i & 0x2 == 0);
  (void)(0 == i & 0x2);
  (void)(i & 0xff < 30);
  (void)((i & 0x2) == 0);
  (void)(i & (0x2 == 0));
  (void)(i == 1 | i == 2 | i == 3);
  (void)(i != 1 & i != 2 & i != 3);
  (void)(i & i | i);
  (void)(i | i & i);
  (void)(i ^ i | i);
  (void)(i | i ^ i);
  (void)(i & i ^ i);
  (void)(i ^ i & i);
  (void)(i ||
             i && i);
  (void)(i || i && "w00t");
  (void)("w00t" && i || i);
  (void)(i || i && "w00t" || i);
  (void)(i || "w00t" && i || i);
  (void)(i && i || 0);
  (void)(0 || i && i);
}
_Bool someConditionFunc();
void conditional_op(int x, int y, _Bool b, void* p) {
  (void)(x + someConditionFunc() ? 1 : 2);
  (void)((x + someConditionFunc()) ? 1 : 2);
  (void)(x - b ? 1 : 2);
  (void)(x * (x == y) ? 1 : 2);
  (void)(x / !x ? 1 : 2);
  (void)(x % 2 ? 1 : 2);
  (void)(x + p ? 1 : 2);
  (void)(p + x ? 1 : 2);
  (void)(p + b ? 1 : 2);
  (void)(x + y > 0 ? 1 : 2);
  (void)(x + (y > 0) ? 1 : 2);
}
