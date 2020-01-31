register unsigned long current_stack_pointer asm("rsp");
struct p4_Thread {
  struct {
    int len;
  } word;
};
register struct p4_Thread *p4TH asm("rsp");
unsigned long get_stack_pointer_addr() {
  return current_stack_pointer;
}
void set_stack_pointer_addr(unsigned long addr) {
  current_stack_pointer = addr;
}
int fn1() {
  return (*p4TH).word.len;
}
void fn2(struct p4_Thread *val) {
  p4TH = val;
}
