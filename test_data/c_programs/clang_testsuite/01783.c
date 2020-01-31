void inline_callee(int i);
void inline_caller() {
  inline_callee(3);
}
void inline_callee(int i) {
  if (i <= 1)
    return;
  inline_callee(i - 1);
}
